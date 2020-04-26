#include "header/search_file.h"
#include "header/main.h"
#include "header/card_service.h"
#include "header/other_log.h"

//��ѯ�û�������
void search_user_total() {
    char name[18];
    char pwd[8];
    Card *p;
    other_log *t;
    struct tm *time;

    printf("�������˺ţ�");
    scanf("%s", name);
    printf("���������룺");
    scanf("%s", pwd);
    p = queryCard(name);

    if ( p != NULL) {

        if ( strcmp(p->aPwd, pwd) == 0 ) {
            t = searchOptLog(name);
            printf("����ʱ��\t���ѽ��\t��������\n");
            while ( t != NULL) {
                time = gmtime(&(t->time));
                printf("%d-%d-%d %d:%d\t%d\t%d\n", 1900 + time->tm_year, 1 + time->tm_mon, time->tm_mday,
                       time->tm_hour, time->tm_min, t->money, t->opt);
                t = t->next;
            }
        } else {
            printf("�������\n");
        }
    } else {
        printf("�޴��û���\n");
    }
}

//��ѯ�û����Ѽ�¼
void search_user_cost_log() {
    char name[18];
    char pwd[8];
    int start_year, start_month, start_day;
    int end_year, end_month, end_day;
    Card *p;
    other_log *t;
    struct tm *time;

    printf("�������˺ţ�");
    scanf("%s", name);
    printf("���������룺");
    scanf("%s", pwd);
    p = queryCard(name);

    if ( p != NULL) {

        if ( strcmp(p->aPwd, pwd) == 0 ) {

            printf("��������ʼʱ�䣨��ʽΪxxxx:xx:xx��:");
            scanf("%d:%d:%d", &start_year, &start_month, &start_day);
            printf("���������ʱ�䣨��ʽΪxxxx:xx:xx��:");
            scanf("%d:%d:%d", &end_year, &end_month, &end_day);
            t = searchOptLog(name);
            printf("����ʱ��\t���ѽ��\t��������\n");
            while ( t != NULL) {
                time = gmtime(&(t->time));
                if ((start_year <= (1900 + time->tm_year)) && (start_month <= (1 + time->tm_mon)) &&
                    (start_day <= time->tm_mday)
                    && (end_year >= (1900 + time->tm_year)) && (end_month >= (time->tm_mon + 1)) &&
                    (end_day >= time->tm_mday)) {
                    printf("%d-%d-%d %d:%d\t%d\t%d\n", 1900 + time->tm_year, 1 + time->tm_mon, time->tm_mday,
                           time->tm_hour, time->tm_min, t->money, t->opt);
                }
                t = t->next;
            }
        } else {
            printf("�������\n");
        }

    } else {
        printf("�޴��û���\n");
    }
}

//��ѯ��Ӫҵ��
void search_total_input() {
    // int start_year, start_month, start_day;
    // int end_year, end_month, end_day;
    other_log *t;
    struct tm *time;
    int money = 0;

    t = heado;

    // printf("��������ʼʱ�䣨��ʽΪxxxx:xx:xx��:");
    // scanf("%4d:%2d:%2d", &start_year, &start_month, &start_day);
    // printf("���������ʱ�䣨��ʽΪxxxx:xx:xx��:");
    // scanf("%4d:%2d:%2d", &end_year, &end_month, &end_day);
    while (t) {
        // time = gmtime(&(t->time));
        // if ((start_year <= (1900 + time->tm_year)) && (start_month <= (1 + time->tm_mon)) &&
        //     (start_day <= time->tm_mday)
        //     && (end_year >= (1900 + time->tm_year)) && (end_month >= (time->tm_mon + 1)) &&
        //     (end_day >= time->tm_mday)) {
            money = money + (t->money);
            t = t->next;
        // }

    }
    printf("��Ӫҵ��Ϊ��%dԪ.\n", money);
}

//��ѯ��Ӫҵ��
void search_total_input_month() {
    int month;
    int money = 0;
    other_log *p;
    struct tm *time;

    p = heado;

    printf("�������·ݣ�");
    scanf("%d", &month);
    while ( p != NULL) {
        time = gmtime(&(p->time));
        if ( month == (time->tm_mon + 1)) {
            money = money + (p->money);
        }
        p = p->next;
    }
    printf("%d�µ�Ӫҵ��Ϊ%dԪ��\n", month, money);
}
