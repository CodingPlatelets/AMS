#include "header/card_file.h"
#include <stdlib.h>

//���濨��Ϣ
int saveCard(char *aName, char *aPwd, float fBalance, struct tm endtm) {
    FILE *fp;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "a+")) == NULL) {  //���ļ�
        printf("File open error!\n");
        return 0;
    }

    fprintf(fp, "%s\t", aName);               //����
    fprintf(fp, "%s\t", aPwd);               //����
    fprintf(fp, "%d\t", 0);                  //��״̬
    fprintf(fp, "%lld\t", time(NULL));       //����ʱ��
    fprintf(fp, "%lld\t", mktime(&endtm));   //����ʱ��
    fprintf(fp, "%f\t", 0.0);              //�ۼƽ��
    fprintf(fp, "%lld\t", time(NULL));      //���ʹ��ʱ��
    fprintf(fp, "%d\t", 0);                //ʹ�ô���
    fprintf(fp, "%f\t", fBalance);        //���
    fprintf(fp, "%d\n", 0);               //ɾ����ʶ

    if ( fclose(fp)) {                    //�ر��ļ�
        printf("Can not close the file!\n");
        return 0;
    }
    return 1;
}


//��ӿ���Ϣ
void updateSave(Card *data) {
    FILE *fp;
    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "a+")) == NULL) {  //���ļ�
        printf("File open error!\n");

    }

    fprintf(fp, "%s\t", data->aName);               //����
    fprintf(fp, "%s\t", data->aPwd);                //����
    fprintf(fp, "%d\t", data->nStatus);             //��״̬
    fprintf(fp, "%lld\t", data->tStart);            //����ʱ��
    fprintf(fp, "%lld\t", data->tEnd);              //����ʱ��
    fprintf(fp, "%f\t", data->fTotalUse);           //�ۼƽ��
    fprintf(fp, "%lld\t", data->tLast);             //���ʹ��ʱ��
    fprintf(fp, "%d\t", data->nUseCount);           //ʹ�ô���
    fprintf(fp, "%f\t", data->fBalance);            //���
    fprintf(fp, "%d\n", data->nDel);                //ɾ����ʶ

    if ( fclose(fp)) {                                     //�ر��ļ�
        printf("Can not close the file!\n");
    }
}

//��д����Ϣ�ļ�
void updateSaveAll() {
    FILE *fp;
    Node *p;
    p = head;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "w+")) == NULL) {
        printf("File open error.\n");
    }

    if ( fclose(fp)) {                    //�ر��ļ�
        printf("Can not close the file!\n");
    }

    while ( p != NULL) {
        if ( p->data != NULL) {
            updateSave(p->data);
        }
        p = p->next;
    }

}

