#include "header/card_service.h"
#include "header/list.h"
#include <string.h>

//��ʼ������
void initCardList() {
    FILE *fp;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "r")) == NULL) {   //���ļ�
        printf("File open error.\n");
        return;
    }
    if (( Node * ) malloc(sizeof(Node)) == NULL) {
        printf("bug\n");
    }
    head = ( Node * ) malloc(sizeof(Node));
    Node *p = head;
    p->data = NULL;
    while ( !feof(fp)) {
        p->data = ( Card * ) malloc(sizeof(Card));
        if ( fscanf(fp, "%s %s %d %lld %lld %f %lld %d %f %d", p->data->aName, p->data->aPwd,
                    &(p->data->nStatus), &(p->data->tStart), &(p->data->tEnd), &(p->data->fTotalUse), &(p->data->tLast),
                    &(p->data->nUseCount), &(p->data->fBalance), &(p->data->nDel)) == -1 ) {
            p->data = NULL;
            break;
        }
        p->next = ( Node * ) malloc(sizeof(Node));      //Ϊp��next�����ڴ��ַ
        p = p->next;                                    //��pָ��������һ���ڵ�
    }
    p->next = NULL;

    if ( fclose(fp)) {                    //�ر��ļ�
        printf("Can not close the file!\n");
    }

}

//��ѯ��
Card *queryCard(char *aName) {
    Node *p = head;
    Node *t = NULL;
    //����������������Ҫ���ҵĿ�����ͬ�Ľṹ��Card��Ϣ��������
    while ( p->data != NULL) {
        if ( strcmp(p->data->aName, aName) == 0 ) {
            t = p;
            return t->data;
        }
        p = p->next;
    }
    //��δ�ҵ�������NULL
    if ( t == NULL) {
        return NULL;
    }
}

//ģ����ѯ��
Node *queryCards(const char *pName) {

    Node *p = head;
    Node *current;                          //����һ��currentָ�룬����Ϊ�׽ڵ㣬���������������ͷ�ѱ���ʼ��ΪNULL��
    current = ( Node * ) malloc(sizeof(Node));
    current->data = NULL;
    current->next = NULL;

    //ʹ��str_str�������Ұ�����Ҫ���ҵĽڵ�
    while ( p != NULL && p->data != NULL) {
        if ( strstr(p->data->aName, pName) != NULL) {
            addToList(p->data, current);  //����addToList������current������ӽ��
        }
        p = p->next;
    }

    return current->next;                   //���صڶ�����㣬��Ϊ��һ������ʼ��ΪNULL

}
