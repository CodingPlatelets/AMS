#pragma once
#ifndef CARD_SERVICE_H
#define CARD_SERVICE_H

#include "header/main.h"

void initCardList();// ��ʼ������
Card *queryCard(char *aName);// ��ѯ��
Node *queryCards(const char *pName);// ģ����ѯ��

#endif
