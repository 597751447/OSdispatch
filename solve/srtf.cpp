//
// Created by shijiajing on 2021/12/17.
//
#include "../common/utils.h"
LinkList Min(LinkList &L,int count)
{
    LinkList p,q,flag;
    int flagnum=0;       //用来标记flag变量值是否改变
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
            flag=q;                           //注意变量q保存的是p所指向的上一节点的信息，一定要引入q，否则会出现调度进程为空的现象
            flagnum=1;
        }
        count--;
        q=p;
        p=p->next;
    }
    if(flagnum==0)
        flag=L;
    return flag;                              //标记最小服务时间的结点的前一个结点的指针
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
        count=getCount(L,time);               //判断当前时间内，就绪队列里有多少进程
        if(count==0)
            time++;                           //如果没有，则将时间加一，再进行判断
        if(count==1)
        {
            q=L;
            p=q->next;
            printf("进程%s执行1min\n",p->data.name);
            time++;
            p->data.Serve_Time--;
            if(p->data.Serve_Time==0)
            {
                printf("进程%s已经完成", p->data.name);
                NowTime(time);
                printf("进程%s的周转时间为：%d\n",p->data.name,time-p->data.Arrive_Time);
                Delet(L,q);                 //【重点】这里的参数一定要填q,而不是p,因为定义的函数Delet删除的是p所指向结点的下一个结点
                flag=1;//标识有用户进程结束了，下一次循环需要调度
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
            printf("进程%s执行1min\n",p->data.name);
            time++;
            p->data.Serve_Time--;
            if(p->data.Serve_Time==0)
            {
                printf("进程%s已经完成", p->data.name);
                NowTime(time);
                printf("进程%s的周转时间为：%d\n",p->data.name,time-p->data.Arrive_Time);
                Delet(L,q);            //同上
                flag=1;//标识有用户进程结束了，下一次循环需要调度
            }
            //Show(L);  调试语句
            printf("\n");
        }
    }
}