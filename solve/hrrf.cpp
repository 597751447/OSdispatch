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


void HRRF(LinkList &L)
{
    int Now,waitTime,i,index;//index记录数组下标
    char nowtime[20];
    LinkList p;
    double rp,highest;//记录响应比和最高响应比
    p=L->next;
    int arriveTime[100],serverTime[100],turnaroundTime[100]={0},finishTime[100]={0};
    i=0;//记录有多少个进程
    while(p!=NULL)
    {
        arriveTime[i]=p->data.Arrive_Time;
        serverTime[i]=p->data.Serve_Time;
        i++;
        p=p->next;
    }
    printf("请输入系统开始时间:\n");
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
        serverTime[index]=-1;//第k个进程已经运行完，置为-1
        finishTime[index]=Now;
        turnaroundTime[index]=finishTime[index]-arriveTime[index];
    }
    show_HHRF(L,turnaroundTime,finishTime);
}