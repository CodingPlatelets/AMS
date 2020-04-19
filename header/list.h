#pragma once

#include "main.h"

void addToList(Card *a, Node *head);// 加入链表
int deleNode(char *aName, Node *head);// 删除节点
Card *searchList(char *aName, Node *head);// 查找链表
void printAll(const Node *head);// 打印所有数据
