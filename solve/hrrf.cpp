//
// Created by 12150 on 2021/12/17.
//

#include "hrrf.h"
#include <stdio.h>
#include <string>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define OVERFLOW -2


int show_HHRF(LinkList &L,int* turnaroundTime,int* finishTime)
{
    LinkList p;
    p=L->next;
    int i=0;
    int sum;
    if(!p)
    {
        printf("Ϊ�գ�\n");
        return ERROR;
    }
    while(p)
    {
        printf("��������%s  ����ʱ�䣺%s  ����ʱ�䣺%d  ���ʱ��:%02d:%02d  ��תʱ��%d\n",
               p->data.name, (p->data.codeTime),p->data.Serve_Time,finishTime[i]/60,finishTime[i]%60,turnaroundTime[i]);
        p=p->next;
        i++;
    }
    return OK;
}


void HRRF(LinkList &L)
{
    int Now,waitTime,i,index;//index��¼�����±�
    char nowtime[20];
    LinkList p;
    double rp,highest;//��¼��Ӧ�Ⱥ������Ӧ��
    p=L->next;
    int arriveTime[100],serverTime[100],turnaroundTime[100]={0},finishTime[100]={0};
    i=0;//��¼�ж��ٸ�����
    while(p!=NULL)
    {
        arriveTime[i]=p->data.Arrive_Time;
        serverTime[i]=p->data.Serve_Time;
        i++;
        p=p->next;
    }
    printf("������ϵͳ��ʼʱ��:\n");
    scanf("%s",nowtime);
    Now= DecodeTime(nowtime);
    for(int j=0;j<i;j++)
    {
        highest=0;
        for (int k=0;k<i;k++)
        {
            waitTime=Now-arriveTime[k];
            rp=(waitTime+serverTime[k])/serverTime[k];
            if(rp>highest)
            {
                highest=rp;
                index=k;
            }
        }
        Now=Now+serverTime[index];
        serverTime[index]=-1;//��k�������Ѿ������꣬��Ϊ-1
        finishTime[index]=Now;
        turnaroundTime[index]=finishTime[index]-arriveTime[index];
    }
    show_HHRF(L,turnaroundTime,finishTime);
}