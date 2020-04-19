#pragma once

#include <time.h>
#include "main.h"

void initOptLog();// 初始化上机状态log 
void addOptLogToList(Card *card, int opt, time_t time, int money, int pre_money, int after_money,
                     other_log *heado);// 添加消费log
other_log *searchOptLog(char *aName);// 查询消费log
