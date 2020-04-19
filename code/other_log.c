#include "header/other_log.h"
#include "header/other_log_file.h"

//��ʼ���ϻ�״̬log
void initOptLog() {
    FILE *fp;
    if ((fp = fopen("D:\\Clion Complier\\Asm\\other_log_info.txt", "r")) == NULL) {   //���ļ�
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
        if ( fscanf(fp, "%s %s %d %lld %lld %f %lld %d %f %d %d %d %d %d %lld", p->card->aName, p->card->aPwd,
                    &(p->card->nStatus), &(p->card->tStart), &(p->card->tEnd), &(p->card->fTotalUse), &(p->card->tLast),
                    &(p->pre_money),
                    &(p->card->nUseCount), &(p->card->fBalance), &(p->card->nDel), &(p->opt), &(p->money),
                    &(p->after_money), &(p->time)) == -1 ) {
            p->card = NULL;
            p->opt = NULL;
            p->money = NULL;
            p->pre_money = NULL;
            p->after_money = NULL;
            p->time = NULL;
            break;
        }
        p->next = ( other_log * ) malloc(sizeof(other_log));   //Ϊp��next�����ڴ��ַ
        p = p->next;                                           //��ָ��p�Ƶ�p��next
    }
    p->next = NULL;

    if ( fclose(fp)) {                                 //�ر��ļ�
        printf("File close error.\n");
    }
}

//�������log
void addOptLogToList(Card *card, int opt, time_t time, int money, int pre_money, int after_money, other_log *heado) {
    other_log *insert;
    other_log *p = heado;
    insert = ( other_log * ) malloc(sizeof(other_log));

    while ( p->next != NULL && p->next->card != NULL) {       //�ҵ�ԭ�����ĩβ
        p = p->next;
    }

    p->next = insert;            //��ԭ�����β�ڵ�ָ��Ҫ����Ľڵ�
    insert->card = card;
    insert->opt = opt;
    insert->money = money;
    insert->pre_money = pre_money;
    insert->after_money = after_money;
    insert->time = time;
    insert->next = NULL;
    //saveOptLog(insert);

}

//��ѯ����log
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
