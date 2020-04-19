#include "header/card_service.h"
#include "header/list.h"
#include <string.h>

//初始化链表
void initCardList() {
    FILE *fp;

    if ((fp = fopen("D:\\Clion Complier\\Asm\\card_info.txt", "r")) == NULL) {   //打开文件
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
        p->next = ( Node * ) malloc(sizeof(Node));      //为p的next申请内存地址
        p = p->next;                                    //把p指向他的下一个节点
    }
    p->next = NULL;

    if ( fclose(fp)) {                    //关闭文件
        printf("Can not close the file!\n");
    }

}

//查询卡
Card *queryCard(char *aName) {
    Node *p = head;
    Node *t = NULL;
    //遍历链表，查找与需要查找的卡号相同的结构体Card信息，并返回
    while ( p->data != NULL) {
        if ( strcmp(p->data->aName, aName) == 0 ) {
            t = p;
            return t->data;
        }
        p = p->next;
    }
    //若未找到，返回NULL
    if ( t == NULL) {
        return NULL;
    }
}

//模糊查询卡
Node *queryCards(const char *pName) {

    Node *p = head;
    Node *current;                          //声明一个current指针，以他为首节点，建立链表（改链表的头已被初始化为NULL）
    current = ( Node * ) malloc(sizeof(Node));
    current->data = NULL;
    current->next = NULL;

    //使用str_str函数查找包含需要查找的节点
    while ( p != NULL && p->data != NULL) {
        if ( strstr(p->data->aName, pName) != NULL) {
            addToList(p->data, current);  //调用addToList函数给current函数添加结点
        }
        p = p->next;
    }

    return current->next;                   //返回第二个结点，因为第一个结点初始化为NULL

}
