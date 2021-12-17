//
// Created by shijiajing on 2021/12/10.
//
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFESIBLE -1
#define OVERFLOW -2
void NowTime(int time)//�����ǰ���е�ʱ��
{
    int hour=time/60;
    int min=time%60;
    if(min<10)
    {
        printf("��ǰʱ��Ϊ%d : 0%d",hour,min);
    }
    else
    printf("��ǰʱ��Ϊ%d : %d",hour,min);
}
int DecodeTime(char time[])
{
    int sum=(10*(time[0]-'0')+(time[1]-'0'))*60+(time[3]-'0')*10+time[4]-'0';
    return sum;
}
int Create(LinkList &L)
{
    LinkList p,r;
    int i,n;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    r=L;
    printf("��������̵ĸ�����\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("��������������\n");
        return ERROR;
    }
    printf("���������������������ʱ�䡢����ʱ�䡢���ȼ�\n");
    for(i=0;i<n;i++)
    {

        p=(LinkList)malloc(sizeof(LNode));
        printf("�����������\n");
        scanf("%s",&(p->data.name));
        printf("�����뵽��ʱ��\n");
        scanf("%s",&(p->data.codeTime));
        p->data.Arrive_Time= DecodeTime(p->data.codeTime);
        //scanf("%d",&(p->data.Arrive_Time));
        printf("���������ʱ��\n");
        scanf("%d",&(p->data.Serve_Time));
        //scanf("%d",&(p->data.Finish_Time));
        printf("���������ȼ�\n");
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
        printf("Ϊ�գ�\n");
        return ERROR;
    }
    while(p)
    {
        printf("��������%s  ����ʱ�䣺%s  ����ʱ�䣺%d  ���ȼ���%d\n",p->data.name, (p->data.codeTime),p->data.Serve_Time,p->data.priority);
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
    while((p!=NULL)&&(p->next!=NULL))       //�������Ķ����������������϶��е�ʱ������ð�����򷨰��յ���ʱ���Ⱥ��������
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
//ɾ����㺯��,ɾ��p����һ�����
void Delet(LinkList &L,LinkList p)
{
    LinkList q;
    q=p->next;
    p->next=q->next;
    free(q);
}
