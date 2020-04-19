#include <time.h>
#include "header/tool.h"

//格式化时间戳
time_t stringToTime(char *s) {

}

//格式化输出卡信息
void printCardInfo(const Card *res) {

    printf("查询到的信息如下：\n");
    printf("卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间\n");

    Card *p = res;

    //输出特定的结构体Card
    struct tm *t = gmtime(&(p->tLast));
    printf("%s\t%d\t%f\t%f\t%d\t%d-%d-%d %d:%d\n", p->aName, p->nStatus, p->fBalance, p->fTotalUse, p->nUseCount,
           1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min);


}
