#pragma once

#include <time.h>
#include "main.h"

void initLoginLog();// ��ʼ��log 
void addLogToList(Card *card, int opt, time_t time);// ���log
login_log *searchLog(char *aName);// ��log
