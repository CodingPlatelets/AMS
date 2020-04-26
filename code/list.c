#include"header/list.h"
#include <stdio.h>
#include <time.h>

//加入链表
void addToList(Card *a, Node *head) {
    Node *p = head;
    Node *insert;

    insert = ( Node * ) malloc(sizeof(Node));

    //找到原链表的最后一个结点
    while ( p->next != NULL && p->next->data != NULL) {
        p = p->next;
    }
    //将新的数据插到最后一个结点的后面
    p->next = insert;
    insert->data = a;
    insert->next = NULL;

}

//删除节点
int deleNode(char *aName, Node *head) {
    Node *p = head;

    while ( p != NULL) {
        if ( strcmp(p->next->data->aName, aName) == 0 ) {
            p->next = p->next->next;
            return 1;         //返回1，表示找到该节点，并且将其删除
        }
    }
    printf("该节点不存在。\n");
    return 0;

}

//打印所有数据
void printAll(const Node *head) {
    printf("查询到的信息如下：\n");
    printf("卡号\t状态\t  余额\t\t累计使用\t 使用次数\t上次使用时间\tVIP\n");
    // printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");
    Node *p = head;

    //遍历以head为首结点的链表，并将其输出
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
