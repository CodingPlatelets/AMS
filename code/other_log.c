#include "header/other_log.h"
#include "header/other_log_file.h"

//初始化上机状态log
void initOptLog() {
    FILE *fp;
    if ((fp = fopen("D:\\Clion Complier\\Asm\\other_log_info.txt", "r")) == NULL) {   //打开文件
        printf("File open error.\n");
    }

    if (( other_log * ) malloc(sizeof(other_log)) == NULL) {
        printf("bug\n");
    }

    heado = ( other_log * ) malloc(sizeof(other_log));
    if ( heado == NULL) {
        printf("bug.\n");
    }
    other_log *p = heado;
    heado->card == NULL;

    while ( !feof(fp)) {
        p->card = ( Card * ) malloc(sizeof(Card));
        if ( fscanf(fp, "%s\t\t%s\t\t%d\t\t%lld\t\t%lld\t\t%f\t\t"
                        "%lld\t\t%d\t\t%f\t\t%d\t\t%d\t\t%f\t\t%f\t\t%f\t\t%lld\t\t%d"
                        ,p->card->aName, p->card->aPwd,
                    &(p->card->nStatus), &(p->card->tStart), &(p->card->tEnd), &(p->card->fTotalUse),
                    &(p->card->tLast),
                    &(p->card->nUseCount),
                    &(p->card->fBalance), &(p->card->nDel), &(p->opt), &(p->money),&(p->pre_money),
                    &(p->after_money), &(p->time), &(p->card->isVip)) == -1 ) {
            p->card = NULL;
            p->opt = 0;
            p->money = 0;
            p->pre_money = 0;
            p->after_money = 0;
            p->time = 0;
            break;
        }
        p->next = ( other_log * ) malloc(sizeof(other_log));   //为p的next申请内存地址
        p = p->next;                                           //把指针p移到p的next
    }
    p->next = NULL;

    if ( fclose(fp)) {                                 //关闭文件
        printf("File close error.\n");
    }
}

//添加消费log
void addOptLogToList(Card *card, int opt, time_t time, int money, int pre_money, int after_money, other_log *heado) {
    other_log *insert;
    other_log *p = heado;
    insert = ( other_log * ) malloc(sizeof(other_log));
    insert->card = card;
    insert->opt = opt;
    insert->money = money;
    insert->pre_money = pre_money;
    insert->after_money = after_money;
    insert->time = time;
    insert->next = NULL;
    while ( p->next != NULL && p->next->card != NULL) {       //找到原链表的末尾
        p = p->next;
    }
    p->next = insert;            //将原链表的尾节点指向要插入的节点
    saveOptLog(insert);

}

//查询消费log
other_log *searchOptLog(char *aName) {
    other_log *p = heado;
    other_log *current;
    current = ( other_log * ) malloc(sizeof(other_log));
    current->card = NULL;
    current->next = NULL;

    while ( p != NULL && p->card != NULL) {
        if ( strcmp(p->card->aName, aName) == 0 ) {
            addOptLogToList(p->card, p->opt, p->time, p->money, p->pre_money, p->after_money, current);
        }
        p = p->next;
    }

    return current->next;
}
