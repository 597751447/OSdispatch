//
// Created by 既然匠子 on 2021/12/17.
//
#include "psAlg.h"
void Psort(LinkList &L){
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
                if(q->data.Arrive_Time==q->next->data.Arrive_Time&&q->data.priority>q->next->data.priority)
                {
                    temp=q->data;
                    q->data=q->next->data;
                    q->next->data=temp;
                }
            }
        }
    }
}
void psa(LinkList &L){
    LinkList p,q;
    p = L;
    while(p->next!=NULL){
        p->data.Arrive_Time = DecodeTime(p->data.codeTime);
        p=p->next;
    }
    //根据开始时间进行排序
    Sort(L);
//    Show(L);

    Psort(L);
//    Show(L);
    int time = L->next->data.Arrive_Time;//进程开始时间
    while(L->next!=NULL){
        printf("进程%s开始调度",L->next->data.name);
        NowTime(time);
        printf("\n");
        printf("进程%s结束调度",L->next->data.name);
        NowTime(time+L->next->data.Serve_Time);
        printf("\n");
        if(L->next->next!=NULL){
            if(time+L->next->data.Serve_Time<L->next->next->data.Arrive_Time){
                time = L->next->next->data.Arrive_Time;
            }
            else{
                time = time+L->next->data.Serve_Time;
            }
        }
        else
        {
            time = L->next->data.Arrive_Time;
        }
        L = L->next;
    }
}
