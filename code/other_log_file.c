#include "header/other_log_file.h"



//��������log�ļ�
void saveOptLog(other_log *log) {
    FILE *fp;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\other_log_info.txt", "a+")) == NULL) {   //���ļ�
        printf("File open error.\n");
    }

    fprintf(fp, "%s\t", log->card->aName);
    fprintf(fp, "%s\t", log->card->aPwd);
    fprintf(fp, "%d\t", log->card->nStatus);
    fprintf(fp, "%lld\t", log->card->tStart);
    fprintf(fp, "%lld\t", log->card->tEnd);
    fprintf(fp, "%f\t", log->card->fTotalUse);
    fprintf(fp, "%lld\t", log->card->tLast);
    fprintf(fp, "%d\t", log->card->nUseCount);
    fprintf(fp, "%f\t", log->card->fBalance);
    fprintf(fp, "%d\t", log->card->nDel);
    fprintf(fp, "%d\t", log->opt);
    fprintf(fp, "%d\t", log->money);
    fprintf(fp, "%d\t", log->pre_money);
    fprintf(fp, "%d\t", log->after_money);
    fprintf(fp, "%lld\t", log->time);
    fprintf(fp, "%d\n",log->card->isVip);

    if ( fclose(fp)) {          //�ر��ļ�
        printf("File close error.\n");
    }
}

//��������log�ļ�
void updateOptLog() {
    FILE *fp;
    other_log *p = heado;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\other_log_info.txt", "w+")) == NULL) {
        printf("File open error.\n");
    }

    if ( fclose(fp)) {                    //�ر��ļ�
        printf("Can not close the file!\n");
    }

    while ( p != NULL) {
        if ( p->card != NULL) {        //
            saveOptLog(p);
        }
        p = p->next;
    }

}
