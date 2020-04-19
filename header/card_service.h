#pragma once
#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H

#include "header/main.h"

void initCardList();// 初始化链表
Card *queryCard(char *aName);// 查询卡
Node *queryCards(const char *pName);// 模糊查询卡

#endif
