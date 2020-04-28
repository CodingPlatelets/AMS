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


int code(){
    char *pwd = (char*)malloc(sizeof(char)*8);
    printf("���������룺");
    scanf("%s",pwd);
    int flag = 0;
    // int cnt = 0;
    while(strcmp(pwd,"huangwenkan")!=0){
        free(pwd);
        pwd = (char*)malloc(sizeof(char)*8);
        char choose[MAX] = "NO";
        printf("��������Ƿ�������룿<'YES'or'NO'>:");
        scanf("%s",choose);
        if(/*choose != 'Y'*/strcmp("YES",choose)){
            printf("����������˳�ϵͳ");
            flag = 1;
            // cnt ++;
            break;
        }else {
            printf("��������������:");
            scanf("%s", pwd);
        }
    }
    // printf("%d",cnt);
    if(flag == 1){
        return 0;
    }else {
        printf("��ӭ���٣�\n");
        return 1;
    }
}
void outputMenu() {
    char * ch = (char*)malloc(sizeof(char)*MAXCARDNUMBER);
    printf("----------�˵�----------\n");
    printf("1:��ӿ�\n");
    printf("2:��ѯ��\n");
    printf("3:�ϻ�\n");
    printf("4:�»�\n");
    printf("5:��ֵ\n");
    printf("6:�˷�\n");
    printf("7:��ѯͳ��\n");
    printf("8:ע��\n");
    printf("9:�޸Ŀ�����\n");
    printf("r:��ע��\n");
    printf("v:��ֵVIP\n");
    printf("0:�˳�ϵͳ\n");
    printf("��ѡ��˵����ţ�");
    // gets(ch);
    scanf("%s",ch);
    while(strlen(ch) >= MAX || !((ch[0] >= '0' && ch[0] <='9') || ch[0] == 'r' || ch[0] == 'v') ){
        free(ch);
        ch = (char*)malloc(sizeof(char)*MAXCARDNUMBER);
        printf("�������룡����������: \n");
        // gets(ch);
        scanf("%s",ch);
    }
    // scanf("%1d", &opt);
    opt = ch[0];
}

//��ӿ�
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

    printf("----------��ӿ�----------\n");
    printf("�����뿨��<����Ϊ1~18>��");
    scanf("%s", name);

    if ( queryCard(name) != NULL) {  //�ж���Ҫ��ӵĿ����Ƿ��Ѿ�����
        printf("�����ѱ�ע�ᡣ\n");
    } else {
        printf("����������<����Ϊ1~8>��");
        scanf("%s", pwd);
        printf("�����뿪�����<RMB>��");
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
        p->isVip = 0;
        addToList(p, head);             //���¿���Ϣ����ӵ�������
        addOptLogToList(p, 1, time(NULL), rmb, 0, p->fBalance, heado);//��ӵ���ֵ������
        // if ((i = saveCard(name, pwd, rmb, endtm)) == 1 ) {
            printf("��ӿ�����Ϣ�ɹ���\n");
        // }

    }


}

//��ѯ��
void printCard() {
    char name[18];
    Node *p;
    printf("----------��ѯ��----------\n");
    printf("�������ѯ�Ŀ���<����Ϊ1~18>��");
    scanf("%s", name);
    p = queryCards(name);       //ģ����ѯ
    if ( p == NULL) {
        printf("δ�ҵ���ؿ��š�\n");
    } else {
        printAll(p);
    }
}

//�ϻ�
void useComputer() {
    char name[18];
    char pwd[8];
    // Card *p;

    printf("----------�ϻ�----------\n");
    printf("�����뿨�ţ�");
    scanf("%s", name);
    printf("����������:");
    scanf("%s", pwd);
    // p = queryCard(name);   //���ò�ѯ�������жϸÿ��Ƿ���ڣ������ڷ��ؿ���Ϣ
    if ( queryCard(name) != NULL) {

        if ( strcmp(queryCard(name)->aPwd, pwd) == 0 ) {   //�ж������Ƿ���ȷ

            if ( queryCard(name)->fBalance > 0 ) {       //�жϿ����Ƿ������

                if ( queryCard(name)->nStatus == 0 ) {   //�жϿ���״̬�Ƿ���δ�ϻ�״̬

                    queryCard(name)->tLast = time(NULL);  //�޸����һ��ʹ�ô˿���ʱ��Ϊ��ǰʱ��
                    queryCard(name)->nStatus = 1;        //������״̬��Ϊ�����ϻ�
                    queryCard(name)->nUseCount++;        //�ÿ���ʹ�ô�����һ
                    printf("�ϻ��ɹ���\n");
                    addLogToList(queryCard(name), 0, time(NULL));
                } else {
                    printf("�ÿ������ϻ�״̬����ע����ʧЧ��\n");
                }
            } else {
                printf("���㡣\n");
            }
        } else {
            printf("�������\n");
        }
    } else {
        printf("�޴��û���\n");
    }

}

//�»�
void exitComputer() {
    char name[18];
    char pwd[8];
    Card *p;
    long long int second;
    double money;
    float balance;

    printf("----------�»�----------\n");
    printf("�������˺ţ�");
    scanf("%s", name);
    printf("���������룺");
    scanf("%s", pwd);
    p = queryCard(name);  //����queryCard������ѯ�ж���������Ŀ��ţ����з��ؿ���Ϣ

    if ( p != NULL) {

        if ( strcmp(p->aPwd, pwd) == 0 ) {  //�ж������Ƿ���ȷ

            if ( p->nStatus == 1 ) {        //�жϿ��Ƿ����ϻ�״̬
                if(!p->isVip) {
                    second = time(NULL) - p->tLast;  //�õ�ǰʱ���ȥ�ϴ�ʹ�ÿ�ϵͳ��ʱ�� ����ʱ��Ϊ�˴��ϻ���ʱ��
                    money = (second / 3600 + !(!(second % 3600))) * price; //������ã�����һ��Сʱ��һ��Сʱ��
                    p->fTotalUse += money;
                    printf("������%.2lfԪ��\n", money);
                } else{
                    second = time(NULL) - p->tLast;  //�õ�ǰʱ���ȥ�ϴ�ʹ�ÿ�ϵͳ��ʱ�� ����ʱ��Ϊ�˴��ϻ���ʱ��
                    money = (second / 3600 + !(!(second % 3600))) * VIP_price; //vip������ã�����һ��Сʱ��һ��Сʱ��
                    p->fTotalUse += money;
                    printf("������%.2lfԪ��\n", money);
                }
                while ( true ) {
                    balance = p->fBalance - money;        //���㿨����ȥ�˴η��õ����
                    if ( balance >= 0 ) {                //�ж�����Ƿ��㹻
                        p->fBalance = balance;        //������㹻���»��ɹ����޸����
                        p->tLast = time(NULL);        //�޸����һ��ʹ��ʱ��Ϊ����ʱ��
                        p->nStatus = 0;              //�޸Ŀ���״̬Ϊδ�ϻ�
                        printf("�»��ɹ���\n");
                        addLogToList(p, 1, time(NULL));
                        // addOptLogToList(p, 2, time(NULL), money, p->fBalance + money,
                        //         p->fBalance, heado);
                        break;
                    } else {
                        printf("���㣬���ֵ%.2lfԪ��\n", money - (p->fBalance));
                        charge();
                    }
                }
            } else {
                printf("���û��������ϻ�״̬����ע����ʧЧ��\n");
            }

        } else {
            printf("�������\n");
        }
    } else {
        printf("�޴��û���\n");
    }

}

//��ֵ
void charge() {
    char name[18];
    char pwd[8];
    float money;
    Card *p;

    printf("----------��ֵ----------\n");
    printf("�������˺ţ�");
    scanf("%s", name);
    printf("���������룺");
    scanf("%s", pwd);
    p = queryCard(name);      //����queryCard������ѯ�ж���������Ŀ��ţ����з��ؿ���Ϣ

    if ( p != NULL) {     //�жϸÿ����Ƿ����

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //�ж������Ƿ���ȷ

            printf("�������ֵ��");    //�����ֵ���
            scanf("%f", &money);
            p->fBalance += money;         //�޸��˻����
            printf("��ֵ�ɹ�����ֵ��Ϣ���£�\n");
            printf("����\t��ֵ���\t���\n");        //����������Ϣ���
            printf("%s\t%.2lf\t%.2lf\n", p->aName, money, p->fBalance);
            addOptLogToList(p, 1, time(NULL), money, p->fBalance - money, p->fBalance, heado);
        } else {
            printf("�������\n");
        }

    } else {
        printf("�޴��û���\n");
    }
}

//�˷�
void withdraw() {
    char name[18];
    char pwd[8];
    Card *p;

    printf("----------�˷�----------\n");
    printf("�������˺ţ�");
    scanf("%s", name);
    printf("���������룺");
    scanf("%s", pwd);
    p = queryCard(name);     //����queryCard������ѯ�ж���������Ŀ��ţ����з��ؿ���Ϣ

    if ( p != NULL) {       //�жϿ��Ƿ����

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //�ж������Ƿ���ȷ

            if ( p->nStatus == 0 ) {    //�жϿ���״̬�Ƿ���δ�ϻ�״̬

                if ( p->fBalance > 0 ) {   //�жϿ����Ƿ������

                    printf("�˷ѽ�%.2lf\n", p->fBalance);
                    printf("�˷ѳɹ���\n");
                    addOptLogToList(p, 2, time(NULL), -(p->fBalance), p->fBalance, 0, heado);
                    p->fBalance = 0;     //���������ĳ�0
                } else {
                    printf("���㣬�˷�ʧ�ܡ�\n");
                }
            } else {
                printf("�ÿ������ϻ�״̬������ע��������ʧЧ���˷�ʧ�ܡ�\n");
            }
        } else {
            printf("��������˷�ʧ�ܡ�\n");
        }
    } else {
        printf("�޴��û����˷�ʧ�ܡ�\n");
    }

}

//��ѯͳ��
void searchAll() {
    int number;

    printf("----------��ѯͳ��----------\n");
    printf("----------�˵�----------\n");
    printf("1.��ѯ�û������Ѽ�¼\n");
    printf("2:��ѯ�û����Ѽ�¼\n");
    printf("3.��ѯ��Ӫҵ��\n");
    printf("4.��ѯ��Ӫҵ��\n");
    printf("������˵����ţ�");
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
            printf("��������ȷ�Ĳ˵����š�\n");
    }
}

//ע��
void exitCard() {
    char name[18];
    char pwd[8];
    Card *p;

    printf("----------ע��----------\n");
    printf("������ע������<����Ϊ1~18>��");
    scanf("%s", name);

    p = queryCard(name);     //����queryCard������ѯ�ж���������Ŀ��ţ����з��ؿ���Ϣ

    if ( p != NULL) {         //�жϸÿ��Ƿ����

        printf("����������<����Ϊ1~8>��");
        scanf("%s", pwd);

        if ( strcmp(p->aPwd, pwd) == 0 ) {   //�ж������Ƿ���ȷ

            if ( p->nStatus == 0 ) {      //�жϿ���״̬�Ƿ���δ�ϻ�

                printf("ע���ɹ���\n");
                printf("����\t�˷ѽ��\n");
                printf("%s\t%.2lf\n", p->aName, p->fBalance);
                addOptLogToList(p, 0, time(NULL), -(p->fBalance), p->fBalance, 0, heado);
                p->fBalance = 0;    //����������Ϊ0
                p->nStatus = 2;     //������״̬��Ϊע��

            } else {
                printf("�ÿ��������ϻ�״̬������ע����ʧЧ��\n");
            }

        } else {
            printf("�������ע��ʧ�ܡ�\n");
        }
    } else {
        printf("�޴��û���\n");
    }
}

//�޸Ŀ�����
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
    printf("----------��������----------\n");
    printf("�����뿨��<����Ϊ1~18>��");
    scanf("%s", name);

    if ( queryCard(name)) {//�ж���Ҫ��ӵĿ����Ƿ��Ѿ�����
        if ( queryCard(name)->nStatus != 2 ) {
            printf("������ԭʼ����<����Ϊ1~8>��");
            scanf("%s", pwd);
            while ( strcmp(queryCard(name)->aPwd, pwd) != 0 ) {
                free(pwd);
                printf("���벻��ȷ!\n");
                printf("����������!\n");
                pwd = ( char * ) malloc(sizeof(char) * 8);
                printf("������ԭ����<����Ϊ1~8>��");
                scanf("%s", pwd);
            }
            printf("�������µ�����:");
            // gets(newPwd);
            scanf("%s", newPwd);
            strcpy(queryCard(name)->aPwd, newPwd);
            printf("�޸ĳɹ���\n");
        } else {
            printf("�ÿ��ѱ�ע����\n");
        }
    } else {
        printf("�ÿ���δע��! \n");

    }
}

void reset(){
    char name[18];
    char *pwd = ( char * ) malloc(sizeof(char) * 8);
    // char pwd[8];
    char newPwd[8];
    printf("----------��ע��----------\n");
    printf("�����뿨��<����Ϊ1~18>��");
    scanf("%s", name);
    if(queryCard(name)){
        queryCard(name)->nStatus = 0;
        printf("�������µ�����<����Ϊ1~8>�� ");
        scanf("%s",newPwd);
        strcpy(queryCard(name)->aPwd, newPwd);
        printf("��ע�Ῠ�ɹ���\n");
        printf("��ע��ʱ��Ϊ��");
        time_t currentTm = time(NULL);
        puts(asctime(localtime(&currentTm)));
    }else{
        printf("�������ڣ�\n");
    }
}
//��ΪVIP

void addVip(){
    char name[18];
    char *pwd = ( char * ) malloc(sizeof(char) * 8);
    int i;
    printf("----------VIP----------\n");
    printf("�����뿨��<����Ϊ1~18>��");
    scanf("%s", name);
    printf("����������<����Ϊ1~8>��");
    scanf("%s", pwd);

    if ( queryCard(name)) {//�ж���Ҫ��ӵĿ����Ƿ��Ѿ�����
        if ( queryCard(name)->nStatus != 2 ) {
            while ( strcmp(queryCard(name)->aPwd, pwd) != 0 ) {
                free(pwd);
                printf("���벻��ȷ!\n");
                printf("����������!\n");
                pwd = ( char * ) malloc(sizeof(char) * 8);
                printf("����������<����Ϊ1~8>��");
                scanf("%s", pwd);
            }
            printf("��ΪVIP��Ҫ�۷�100,�Ƿ����?(1Ϊ������0Ϊ�˳�): ");
            int y = 0;
            scanf("%d",&y);
            if(y == 1){
                if(queryCard(name)->fBalance >= 100) {
                    printf("��ϲ��ΪVIP�û�\n");
                    queryCard(name)->fBalance = queryCard(name)->fBalance - 100;
                    queryCard(name)->fTotalUse += 100;
                    queryCard(name)->isVip = 1;
                    printf("��Ŀǰ�����Ϊ��%.2f\n", queryCard(name)->fBalance);
                    addOptLogToList(queryCard(name), 1, time(NULL), 100,
                            queryCard(name)->fBalance + 100, queryCard(name)->fBalance + 200, heado);
                }else{
                    printf("���㣬���ֵ��\n");
                    charge();
                }
            }
        } else {
            printf("�ÿ��ѱ�ע����\n");
        }
    } else {
        printf("�ÿ���δע��! \n");
    }
}