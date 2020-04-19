#pragma once

#include <time.h>
#include "main.h"

void initLoginLog();// 初始化log 
void addLogToList(Card *card, int opt, time_t time);// 添加log
login_log *searchLog(char *aName);// 查log
