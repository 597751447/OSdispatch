//
// Created by shijiajing on 2021/12/17.
//
#include "../common/utils.h"
LinkList Min(LinkList &L,int count)
{
    LinkList p,q,flag;
    int flagnum=0;       //�������flag����ֵ�Ƿ�ı�
    int min;
    p=L->next;
    q=L->next;
    flag=L->next;
    min=p->data.Serve_Time;
    while(count>0)
    {
        if(p->data.Serve_Time<min)
        {
            min=p->data.Serve_Time;
            flag=q;                           //ע�����q�������p��ָ�����һ�ڵ����Ϣ��һ��Ҫ����q���������ֵ��Ƚ���Ϊ�յ�����
            flagnum=1;
        }
        count--;
        q=p;
        p=p->next;
    }
    if(flagnum==0)
        flag=L;
    return flag;                              //�����С����ʱ��Ľ���ǰһ������ָ��
}
void Srtf(LinkList &L)
{
    int time=0,count;
    LinkList p,q;
    LinkList oldq;
    while(L->next!=NULL)
    {
        int flag=0;
        int oldcount=0;
        count=getCount(L,time);               //�жϵ�ǰʱ���ڣ������������ж��ٽ���
        if(count==0)
            time++;                           //���û�У���ʱ���һ���ٽ����ж�
        if(count==1)
        {
            q=L;
            p=q->next;
            printf("����%sִ��1min\n",p->data.name);
            time++;
            p->data.Serve_Time--;
            if(p->data.Serve_Time==0)
            {
                printf("����%s�Ѿ����", p->data.name);
                NowTime(time);
                printf("����%s����תʱ��Ϊ��%d\n",p->data.name,time-p->data.Arrive_Time);
                Delet(L,q);                 //���ص㡿����Ĳ���һ��Ҫ��q,������p,��Ϊ����ĺ���Deletɾ������p��ָ�������һ�����
                flag=1;//��ʶ���û����̽����ˣ���һ��ѭ����Ҫ����
            }
            printf("\n");
            oldcount=1;
        }
        if(count>=2)
        {
            if(flag==1||oldcount!=count)
            {
                q=Min(L,count);
                oldq=q;
                p=q->next;
                flag=0;
                oldcount=count;
            }
            q=oldq;
            p=q->next;
            printf("����%sִ��1min\n",p->data.name);
            time++;
            p->data.Serve_Time--;
            if(p->data.Serve_Time==0)
            {
                printf("����%s�Ѿ����", p->data.name);
                NowTime(time);
                printf("����%s����תʱ��Ϊ��%d\n",p->data.name,time-p->data.Arrive_Time);
                Delet(L,q);            //ͬ��
                flag=1;//��ʶ���û����̽����ˣ���һ��ѭ����Ҫ����
            }
            //Show(L);  �������
            printf("\n");
        }
    }
}