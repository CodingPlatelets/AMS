#pragma once
#ifndef CARD_FILE_H
#define CARD_FILE_H
#include "main.h"

int saveCard(char *aName, char *aPwd, float fBalance, struct tm endtm);// 保存卡信息
int readCard();// 读取卡信息 
int parseCard();// 格式化卡信息 
void updateSave(Card *data);// 添加卡信息
void updateSaveAll();// 重写卡信息文件 

#endif
