//
// Created by 12150 on 2021/12/17.
//

//
// Created by 12150 on 2021/12/17.
//

#include "fcfs.h"
#include <stdio.h>
#include <string>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define OVERFLOW -2


int show_FCFS(LinkList &L,int* turnaroundTime,int* finishTime)
{
    LinkList p;
    p=L->next;
    int i=0;
    int sum;
    if(!p)
    {
        printf("为空！\n");
        return ERROR;
    }
    while(p)
    {
        printf("进程名：%s  到达时间：%s  服务时间：%d  完成时间:%02d:%02d  周转时间%d\n",
               p->data.name, (p->data.codeTime),p->data.Serve_Time,finishTime[i]/60,finishTime[i]%60,turnaroundTime[i]);
        p=p->next;
        i++;
    }
    return OK;
}


void FCFS(LinkList &L)
{
    LinkList p;
    p=L->next;
    int arriveTime[100],serverTime[100],turnaroundTime[100]={0},finishTime[100]={0};
    int i=0,Now;
    while(p!=NULL)
    {
        arriveTime[i]=p->data.Arrive_Time;
        serverTime[i]=p->data.Serve_Time;
        i++;
        p=p->next;
    }
    Now=arriveTime[0];
    for(int j=0;j<i;j++)
    {

        finishTime[j]=Now+serverTime[j];
        turnaroundTime[j]=finishTime[j]-arriveTime[j];
        Now=Now+serverTime[j];
    }
    show_FCFS(L,turnaroundTime,finishTime);
}

