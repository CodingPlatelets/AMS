#include <time.h>
#include "header/tool.h"

//��ʽ��ʱ���
time_t stringToTime(char *s) {

}

//��ʽ���������Ϣ
void printCardInfo(const Card *res) {

    printf("��ѯ������Ϣ���£�\n");
    printf("����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");

    Card *p = res;

    //����ض��Ľṹ��Card
    struct tm *t = gmtime(&(p->tLast));
    printf("%s\t%d\t%f\t%f\t%d\t%d-%d-%d %d:%d\n", p->aName, p->nStatus, p->fBalance, p->fTotalUse, p->nUseCount,
           1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min);


}
