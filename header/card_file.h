#pragma once
#ifndef CARD_FILE_H
#define CARD_FILE_H
#include "main.h"

int saveCard(char *aName, char *aPwd, float fBalance, struct tm endtm);// ���濨��Ϣ
int readCard();// ��ȡ����Ϣ 
int parseCard();// ��ʽ������Ϣ 
void updateSave(Card *data);// ��ӿ���Ϣ
void updateSaveAll();// ��д����Ϣ�ļ� 

#endif
