#include "header/menu.h"
#include "header/main.h"
#include "header/card_service.h"
#include "header/card_file.h"
#include "header/list.h"
#include "header/other_log.h"
#include "header/login_log.h"
#include "header/search_file.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX 2

void outputMenu() {
    char * ch = (char*)malloc(sizeof(char)*MAXCARDNUMBER);
    printf("----------菜单----------\n");
    printf("1:添加卡\n");
    printf("2:查询卡\n");
    printf("3:上机\n");
    printf("4:下机\n");
    printf("5:充值\n");
    printf("6:退费\n");
    printf("7:查询统计\n");
    printf("8:注销\n");
    printf("9:修改卡密码\n");
    printf("0:退出系统\n");
    printf("请选择菜单项编号：");
    // gets(ch);
    scanf("%s",ch);
    while(strlen(ch) >= MAX || !((ch[0] >= '0' && ch[0] <='9') || ch[0] == 'r') ){
        free(ch);
        ch = (char*)malloc(sizeof(char)*MAXCARDNUMBER);
        printf("错误输入！请重新输入: \n");
        // gets(ch);
        scanf("%s",ch);
    }
    // scanf("%1d", &opt);
    opt = (int)ch[0];
}

//添加卡
void addCard() {
    char name[18];
    char pwd[8];
    double rmb;
    Card *p;
    p = ( Card * ) malloc(sizeof(Card));
    int i;
    struct tm endtm;

    endtm.tm_year = 2025;
    endtm.tm_mon = 1;
    endtm.tm_mday = 1;

    printf("----------添加卡----------\n");
    printf("请输入卡号<长度为1~18>：");
    scanf("%s", name);

    if ( queryCard(name) != NULL) {  //判断想要添加的卡号是否已经存在
        printf("卡号已被注册。\n");
    } else {
        printf("请输入密码<长度为1~8>：");
        scanf("%s", pwd);
        printf("请输入开卡金额<RMB>：");
        scanf("%lf", &rmb);
        strcpy(p->aName, name);
        strcpy(p->aPwd, pwd);
        p->fBalance = rmb;
        p->nStatus = 0;
        p->tStart = time(NULL);
        p->fTotalUse = 0;
        p->tLast = time(NULL);
        p->nUseCount = 0;
        p->nDel = 0;
        addToList(p, head);             //将新卡信息，添加到链表中
        if ((i = saveCard(name, pwd, rmb, endtm)) == 1 ) {
            printf("添加开卡信息成功！\n");
        }

    }


}

//查询卡
void printCard() {
    char name[18];
    Node *p;
    printf("----------查询卡----------\n");
    printf("请输入查询的卡号<长度为1~18>；");
    scanf("%s", name);
    p = queryCards(name);       //模糊查询
    if ( p == NULL) {
        printf("未找到相关卡号。\n");
    } else {
        printAll(p);
    }
}

//上机
void useComputer() {
    char name[18];
    char pwd[8];
    Card *p;

    printf("----------上机----------\n");
    printf("请输入卡号：");
    scanf("%s", name);
    printf("请输入密码:");
    scanf("%s", pwd);
    p = queryCard(name);   //调用查询卡函数判断该卡是否存在，若存在返回卡信息
    if ( p != NULL) {

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //判断密码是否正确

            if ( p->fBalance > 0 ) {       //判断卡内是否还有余额

                if ( p->nStatus == 0 ) {   //判断卡的状态是否处于未上机状态

                    p->tLast = time(NULL);  //修改最后一次使用此卡的时间为当前时间
                    p->nStatus = 1;        //将卡的状态改为正在上机
                    p->nUseCount++;        //该卡的使用次数加一
                    printf("上机成功！\n");
                    addLogToList(p, 0, time(NULL));
                } else {
                    printf("该卡处于上机状态或已注销或失效。\n");
                }
            } else {
                printf("余额不足。\n");
            }
        } else {
            printf("密码错误。\n");
        }
    } else {
        printf("无此用户。\n");
    }

}

//下机
void exitComputer() {
    char name[18];
    char pwd[8];
    Card *p;
    long long int second;
    double money;
    float balance;

    printf("----------下机----------\n");
    printf("请输入账号：");
    scanf("%s", name);
    printf("请输入密码：");
    scanf("%s", pwd);
    p = queryCard(name);  //调用queryCard函数查询判断有无输入的卡号，若有返回卡信息

    if ( p != NULL) {

        if ( strcmp(p->aPwd, pwd) == 0 ) {  //判断密码是否正确

            if ( p->nStatus == 1 ) {        //判断卡是否处于上机状态

                second = time(NULL) - p->tLast;  //用当前时间减去上次使用卡系统的时间 计算时间差，为此次上机总时间
                money = (second / 3600 + !(!(second % 3600))) * price; //计算费用，不足一个小时按一个小时算
                p->fTotalUse += money;
                printf("花费了%.2lf元。\n", money);
                while ( true ) {
                    balance = p->fBalance - money;        //计算卡余额减去此次费用的余额
                    if ( balance >= 0 ) {                //判断余额是否足够
                        p->fBalance = balance;        //若余额足够，下机成功，修改余额
                        p->tLast = time(NULL);        //修改最后一次使用时间为本次时间
                        p->nStatus = 0;              //修改卡的状态为未上机
                        printf("下机成功！\n");
                        addLogToList(p, 1, time(NULL));
                        break;
                    } else {
                        printf("余额不足，请充值%.2lf元。\n", money - (p->fBalance));
                        charge();
                    }
                }
            } else {
                printf("该用户不处于上机状态或已注销或失效。\n");
            }

        } else {
            printf("密码错误。\n");
        }
    } else {
        printf("无此用户。\n");
    }

}

//充值
void charge() {
    char name[18];
    char pwd[8];
    float money;
    Card *p;

    printf("----------充值----------\n");
    printf("请输入账号：");
    scanf("%s", name);
    printf("请输入密码：");
    scanf("%s", pwd);
    p = queryCard(name);      //调用queryCard函数查询判断有无输入的卡号，若有返回卡信息

    if ( p != NULL) {     //判断该卡号是否存在

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //判断密码是否正确

            printf("请输入充值金额：");    //输入充值金额
            scanf("%f", &money);
            p->fBalance += money;         //修改账户余额
            printf("充值成功，充值信息如下：\n");
            printf("卡号\t充值金额\t余额\n");        //将卡部分信息打表
            printf("%s\t%.2lf\t%.2lf\n", p->aName, money, p->fBalance);
            addOptLogToList(p, 1, time(NULL), money, p->fBalance - money, p->fBalance, heado);
        } else {
            printf("密码错误。\n");
        }

    } else {
        printf("无此用户。\n");
    }
}

//退费
void withdraw() {
    char name[18];
    char pwd[8];
    Card *p;

    printf("----------退费----------\n");
    printf("请输入账号：");
    scanf("%s", name);
    printf("请输入密码：");
    scanf("%s", pwd);
    p = queryCard(name);     //调用queryCard函数查询判断有无输入的卡号，若有返回卡信息

    if ( p != NULL) {       //判断卡是否存在

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //判断密码是否正确

            if ( p->nStatus == 0 ) {    //判断卡的状态是否处于未上机状态

                if ( p->fBalance > 0 ) {   //判断卡内是否有余额

                    printf("退费金额：%.2lf\n", p->fBalance);
                    printf("退费成功！\n");
                    addOptLogToList(p, 2, time(NULL), p->fBalance, p->fBalance, 0, heado);
                    p->fBalance = 0;     //将卡内余额改成0
                } else {
                    printf("余额不足，退费失败。\n");
                }
            } else {
                printf("该卡处于上机状态，或已注销，或已失效，退费失败。\n");
            }
        } else {
            printf("密码错误，退费失败。\n");
        }
    } else {
        printf("无此用户，退费失败。\n");
    }

}

//查询统计
void searchAll() {
    int number;

    printf("----------查询统计----------\n");
    printf("----------菜单----------\n");
    printf("1.查询用户总消费记录\n");
    printf("2:查询用户消费记录\n");
    printf("3.查询总营业额\n");
    printf("4.查询月营业额\n");
    printf("请输入菜单项编号：");
    scanf("%d", &number);
    switch ( number ) {
        case 1:
            search_user_total();
            break;
        case 2:
            search_user_cost_log();
            break;
        case 3:
            search_total_input();
            break;
        case 4:
            search_total_input_month();
            break;
        default:
            printf("请输入正确的菜单项编号。\n");
    }
}

//注销
void exitCard() {
    char name[18];
    char pwd[8];
    Card *p;

    printf("----------注销----------\n");
    printf("请输入注销卡号<长度为1~18>：");
    scanf("%s", name);

    p = queryCard(name);     //调用queryCard函数查询判断有无输入的卡号，若有返回卡信息

    if ( p != NULL) {         //判断该卡是否存在

        printf("请输入密码<长度为1~8>：");
        scanf("%s", pwd);

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //判断密码是否正确

            if ( p->nStatus == 0 ) {      //判断卡的状态是否处于未上机

                printf("注销成功！\n");
                printf("卡号\t退费金额\n");
                printf("%s\t%.2lf\n", p->aName, p->fBalance);
                p->fBalance = 0;    //将卡的余额改为0
                p->nStatus = 2;     //将卡的状态改为注销
                addOptLogToList(p, 0, time(NULL), 0, 0, 0, heado);
            } else {
                printf("该卡正处于上机状态，或已注销或失效。\n");
            }

        } else {
            printf("密码错误，注销失败。\n");
        }
    } else {
        printf("无此用户。\n");
    }
}

//修改卡密码
void changePwd() {

    char name[18];
    char *pwd = ( char * ) malloc(sizeof(char) * 8);
    // char pwd[8];
    char newPwd[8];
    Card *p;
    int i;
    // Card *ch;
    // ch = queryCard(name);
    p = ( Card * ) malloc(sizeof(Card));
    printf("----------更改密码----------\n");
    printf("请输入卡号<长度为1~18>：");
    scanf("%s", name);

    if ( queryCard(name)) {//判断想要添加的卡号是否已经存在
        if ( queryCard(name)->nStatus != 2 ) {
            printf("请输入原始密码<长度为1~8>：");
            scanf("%s", pwd);
            while ( strcmp(queryCard(name)->aPwd, pwd) != 0 ) {
                free(pwd);
                printf("密码不正确!\n");
                printf("请重新输入!\n");
                pwd = ( char * ) malloc(sizeof(char) * 8);
                printf("请输入原密码<长度为1~8>：");
                scanf("%s", pwd);
            }
            printf("请输入新的密码:");
            // gets(newPwd);
            scanf("%s", newPwd);
            strcpy(queryCard(name)->aPwd, newPwd);
            printf("修改成功！\n");
        } else {
            printf("该卡已被注销！\n");
        }
    } else {
        printf("该卡尚未注册! \n");

    }
}

void reset(){
    char name[18];
    char *pwd = ( char * ) malloc(sizeof(char) * 8);
    // char pwd[8];
    char newPwd[8];
    printf("----------重注册----------\n");
    printf("请输入卡号<长度为1~18>：");
    scanf("%s", name);
    if(queryCard(name)){
        queryCard(name)->nStatus = 0;
        printf("请输入新的密码<长度为1~8>： ");
        scanf("%s",newPwd);
        strcpy(queryCard(name)->aPwd, newPwd);
        printf("重注册卡成功！\n");
        printf("重注册时间为：");
        time_t currentTm = time(NULL);
        puts(asctime(localtime(&currentTm)));
    }else{
        printf("卡不存在！\n");
    }
}