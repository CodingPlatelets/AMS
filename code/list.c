#include"header/list.h"
#include <stdio.h>
#include <time.h>

//��������
void addToList(Card *a, Node *head) {
    Node *p = head;
    Node *insert;

    insert = ( Node * ) malloc(sizeof(Node));

    //�ҵ�ԭ��������һ�����
    while ( p->next != NULL && p->next->data != NULL) {
        p = p->next;
    }
    //���µ����ݲ嵽���һ�����ĺ���
    p->next = insert;
    insert->data = a;
    insert->next = NULL;

}

//ɾ���ڵ�
int deleNode(char *aName, Node *head) {
    Node *p = head;

    while ( p != NULL) {
        if ( strcmp(p->next->data->aName, aName) == 0 ) {
            p->next = p->next->next;
            return 1;         //����1����ʾ�ҵ��ýڵ㣬���ҽ���ɾ��
        }
    }
    printf("�ýڵ㲻���ڡ�\n");
    return 0;

}

//��ӡ��������
void printAll(const Node *head) {
    printf("��ѯ������Ϣ���£�\n");
    printf("����\t״̬\t  ���\t\t�ۼ�ʹ��\t ʹ�ô���\t�ϴ�ʹ��ʱ��\tVIP\n");
    // printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
    Node *p = head;

    //������headΪ�׽����������������
    while ( p != NULL) {

        struct tm *t = gmtime(&(p->data->tLast));
        // printf("%s\t%d\t%.3f\t %.3f\t\t%d\t%d-%d-%d %d:%d\n", p->data->aName, p->data->nStatus, p->data->fBalance,
        //        p->data->fTotalUse,
        //        p->data->nUseCount, 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min);
        printf("%s\t%-1d\t%.3f   \t%.3f\t\t%d\t%d-%d-%d %d:%d\t%d\n", p->data->aName, p->data->nStatus, p->data->fBalance,
               p->data->fTotalUse,
               p->data->nUseCount, 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min,p->data->isVip);

        p = p->next;

    }

}
