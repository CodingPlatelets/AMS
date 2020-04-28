#include "header/login_log_file.h"

//保存Log文件
void saveLog(login_log *log) {
    FILE *fp;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\login_log_info.txt", "a+")) == NULL) {   //打开文件
        printf("File open error.\n");
    }

    fprintf(fp, "%s\t\t", log->card->aName);
    fprintf(fp, "%s\t\t", log->card->aPwd);
    fprintf(fp, "%d\t\t", log->card->nStatus);
    fprintf(fp, "%lld\t\t", log->card->tStart);
    fprintf(fp, "%lld\t\t", log->card->tEnd);
    fprintf(fp, "%.2f\t\t", log->card->fTotalUse);
    fprintf(fp, "%lld\t\t", log->card->tLast);
    fprintf(fp, "%d\t\t", log->card->nUseCount);
    fprintf(fp, "%.2f\t\t", log->card->fBalance);
    fprintf(fp, "%d\t\t", log->card->nDel);
    fprintf(fp, "%d\t\t", log->opt);
    fprintf(fp, "%lld\t\t", log->time);
    fprintf(fp, "%d\n",log->card->isVip);

    if ( fclose(fp)) {          //关闭文件
        printf("File close error.\n");
    }

}

//更新Log文件
void updateLog() {

    FILE *fp;
    login_log *p;
    p = headl;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\login_log_info.txt", "w+")) == NULL) {
        printf("File open error.\n");
    }

    if ( fclose(fp)) {                    //关闭文件
        printf("Can not close the file!\n");
    }

    while ( p != NULL) {
        if ( p->card != NULL) {        //
            saveLog(p);
        }
        p = p->next;
    }
}
