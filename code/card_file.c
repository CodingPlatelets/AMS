#include "header/card_file.h"
#include <stdlib.h>

//保存卡信息
int saveCard(char *aName, char *aPwd, float fBalance, struct tm endtm) {
    FILE *fp;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "a+")) == NULL) {  //打开文件
        printf("File open error!\n");
        return 0;
    }

    fprintf(fp, "%s\t", aName);                 //卡号
    fprintf(fp, "%s\t", aPwd);                  //密码
    fprintf(fp, "%d\t", 0);                     //卡状态
    fprintf(fp, "%lld\t", time(NULL));    //开卡时间
    fprintf(fp, "%lld\t", mktime(&endtm));      //截至时间
    fprintf(fp, "%.2f\t", 0.0);                   //累计金额
    fprintf(fp, "%lld\t", time(NULL));    //最后使用时间
    fprintf(fp, "%d\t", 0);                     //使用次数
    fprintf(fp, "%.2f\t", fBalance);              //余额
    fprintf(fp, "%d\t", 0);                     //删除标识
    fprintf(fp,"%d\n",0);                       //vip标识

    if ( fclose(fp)) {                    //关闭文件
        printf("Can not close the file!\n");
        return 0;
    }
    return 1;
}


//添加卡信息
void updateSave(Card *data) {
    FILE *fp;
    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "a+")) == NULL) {  //打开文件
        printf("File open error!\n");

    }

    fprintf(fp, "%s\t\t", data->aName);               //卡号
    fprintf(fp, "%s\t\t", data->aPwd);                //密码
    fprintf(fp, "%d\t\t", data->nStatus);             //卡状态
    fprintf(fp, "%lld\t\t", data->tStart);            //开卡时间
    fprintf(fp, "%lld\t\t", data->tEnd);              //截至时间
    fprintf(fp, "%.2f\t\t", data->fTotalUse);           //累计金额
    fprintf(fp, "%lld\t\t", data->tLast);             //最后使用时间
    fprintf(fp, "%d\t\t", data->nUseCount);           //使用次数
    fprintf(fp, "%.2f\t\t", data->fBalance);            //余额
    fprintf(fp, "%d\t\t", data->nDel);                //删除标识
    fprintf(fp,"%d\n",data->isVip);                   //VIP

    if ( fclose(fp)) {                                     //关闭文件
        printf("Can not close the file!\n");
    }
}

//重写卡信息文件
void updateSaveAll() {
    FILE *fp;
    Node *p;
    p = head;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "w+")) == NULL) {
        printf("File open error.\n");
    }

    if ( fclose(fp)) {                    //关闭文件
        printf("Can not close the file!\n");
    }

    while ( p != NULL) {
        if ( p->data != NULL) {
            updateSave(p->data);
        }
        p = p->next;
    }

}

