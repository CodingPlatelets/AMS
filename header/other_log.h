#pragma once

#include <time.h>
#include "main.h"

void initOptLog();// ��ʼ���ϻ�״̬log 
void addOptLogToList(Card *card, int opt, time_t time, int money, int pre_money, int after_money,
                     other_log *heado);// �������log
other_log *searchOptLog(char *aName);// ��ѯ����log
