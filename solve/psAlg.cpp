//
// Created by ��Ȼ���� on 2021/12/17.
//
#include "psAlg.h"
void Psort(LinkList &L){
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
    //���ݿ�ʼʱ���������
    Sort(L);
//    Show(L);

    Psort(L);
//    Show(L);
    int time = L->next->data.Arrive_Time;//���̿�ʼʱ��
    while(L->next!=NULL){
        printf("����%s��ʼ����",L->next->data.name);
        NowTime(time);
        printf("\n");
        printf("����%s��������",L->next->data.name);
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
