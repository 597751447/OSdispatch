//
// Created by shijiajing on 2021/12/10.
//
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define OVERFLOW -2
int Create(LinkList &L)
{
    LinkList p,r;
    int i,n;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    r=L;
    printf("请输入进程的个数：\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("请输入正整数！\n");
        return ERROR;
    }
    printf("请依次输入进程名、到达时间、服务时间、优先级\n");
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%s",&(p->data.name));
        scanf("%d",&(p->data.Arrive_Time));
        scanf("%d",&(p->data.Serve_Time));
        //scanf("%d",&(p->data.Finish_Time));
        scanf("%d",&(p->data.priority));
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return OK;
}
int Show(LinkList L)
{
    LinkList p;
    p=L->next;
    if(!p)
    {
        printf("为空！\n");
        return ERROR;
    }
    while(p)
    {
        printf("进程名：%s  到达时间：%d  服务时间：%d  优先级：%d\n",p->data.name,p->data.Arrive_Time,p->data.Serve_Time,p->data.priority);
        p=p->next;
    }
    return OK;
}
void Sort(LinkList &L)
{
    LinkList p,q;
    PCB temp;
    p=L->next;
    q=L->next;
    while((p!=NULL)&&(p->next!=NULL))       //当创建的队列中有两个及以上队列的时候，利用冒泡排序法按照到达时间先后进行排序
    {
        for(p=L->next;p->next!=NULL;p=p->next)
        {
            for(q=L->next;q->next!=NULL;q=q->next)
            {
                if(q->data.Arrive_Time>q->next->data.Arrive_Time)
                {
                    temp=q->data;
                    q->data=q->next->data;
                    q->next->data=temp;
                }
            }
        }
    }
}
int getCount(LinkList &L,int time)
{
    int count=0;
    LinkList q;
    q=L->next;
    while(q!=NULL&&q->data.Arrive_Time<=time)
    {
        count++;
        q=q->next;
    }
    return count;
}
//删除结点函数,删除p的下一个结点
void Delet(LinkList &L,LinkList p)
{
    LinkList q;
    q=p->next;
    p->next=q->next;
    free(q);
}
