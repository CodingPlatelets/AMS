#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXCARDNUMBER 100000
#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define true 1
#define false 0
#define price 1

typedef struct Card {
    char aName[18];         //����
    char aPwd[8];           //����
    int nStatus;            //��״̬��0-δ�ϻ���1-�����ϻ���2-��ע����3-ʧЧ��
    time_t tStart;          //����ʱ��
    time_t tEnd;            //���Ľ�ֹʱ��
    float fTotalUse;        //�ۼƽ��
    time_t tLast;           //���ʹ��ʱ��
    int nUseCount;          //ʹ�ô���
    float fBalance;         //���
    int nDel;               //ɾ����ʶ 0-δɾ����1-ɾ��
} Card;

typedef struct Node {
    Card *data;
    struct Node *next;
} Node;

typedef struct login_log {
    Card *card;
    int opt;                // opt-1:�»� 0:�ϻ�
    time_t time;
    struct login_log *next;
} login_log;

typedef struct other_log {
    Card *card;
    int opt;               // opt-0:ע���� 1:��ֵ 2:�˷�
    int money;             // ��opt==1 or 2ʱ���������漰�Ľ�� ��opt==0:money=0
    int pre_money;         // ��opt==1 or 2ʱ������ǰ�Ľ�� ��opt==0:pre_money=0
    int after_money;       // ��opt==1 or 2ʱ��������Ľ�� ��opt==0:after_money=0
    time_t time;
    struct other_log *next;
} other_log;

//ȫ�ֱ���
int opt;                    // �ϻ�״̬
int nowCardNum;
Node card;                  // ������
Node *head;
login_log loginLog;         // ��¼����log����
login_log *headl;
other_log optLog;           // ����log����
other_log *heado;

#endif
