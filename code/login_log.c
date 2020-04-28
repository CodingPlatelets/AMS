#include "header/login_log.h"
#include "header/login_log_file.h"

//初始化Log
void initLoginLog() {
    FILE *fp;
    if ((fp = fopen("D:\\Clion Complier\\Asm\\login_log_info.txt", "r")) == NULL) {   //打开文件
        printf("File open error.\n");
    }

    headl = ( login_log * ) malloc(sizeof(login_log));
    login_log *p = headl;
    headl->card == NULL;

    while ( !feof(fp)) {
        p->card = ( Card * ) malloc(sizeof(Card));
        if ( fscanf(fp, "%s\t\t%s\t\t%d\t\t%lld\t\t"
                        "%lld\t\t%f\t\t%lld\t\t%d\t\t"
                        "%f\t\t%d\t\t%d\t\t%lld\t\t%d",
                        p->card->aName, p->card->aPwd,
                    &(p->card->nStatus), &(p->card->tStart),
                    &(p->card->tEnd), &(p->card->fTotalUse),
                    &(p->card->tLast),&(p->card->nUseCount),
                    &(p->card->fBalance), &(p->card->nDel),
                    &(p->opt), &(p->time),&(p->card->isVip)) == -1 ) {
            p->card = NULL;
            p->opt = NULL;
            p->time = NULL;
            break;
        }
        p->next = ( login_log * ) malloc(sizeof(login_log));   //为p的next申请内存地址
        p = p->next;                                       //把指针p移到p的next
    }
    p->next = NULL;

    if ( fclose(fp)) {                                 //关闭文件
        printf("File close error.\n");
    }
}

//添加Log
void addLogToList(Card *card, int opt, time_t time) {
    login_log *p = headl;
    login_log *insert;
    insert = ( login_log * ) malloc(sizeof(login_log));

    while ( p->next != NULL && p->next->card != NULL) {
        p = p->next;
    }

    insert->card = card;
    insert->opt = opt;
    insert->time = time;
    insert->next = NULL;
    p->next = insert;
    saveLog(insert);

}

//查Log
login_log *searchLog(char *aName) {
    login_log *p = headl;
    login_log *t = NULL;

    while ( p->card != NULL) {
        if ( strcmp(p->card->aName, aName) == 0 ) {
            t = p;
            return t;
        }
        p = p->next;
    }

    if ( t == NULL) {
        return NULL;
    }
}
