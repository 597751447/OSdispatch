//
// Created by shijiajing on 2021/12/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef OSDISPATCH_UTILS_H
#define OSDISPATCH_UTILS_H
#pragma once
#endif //OSDISPATCH_UTILS_H

struct PCB //PCB�ṹ��
{
    char name[20];       //������
    char codeTime[20];
    int Arrive_Time;     //����ʱ��
    int Serve_Time;      //����ʱ��
    //int Finish_Time;     //���ʱ��
    int priority;        //���ȼ�
};
typedef struct LNode            //�����㶨��
{
    PCB data;
    struct LNode *next;
}LNode,*LinkList;
//����β�巨��������
int Create(LinkList &L);
//���������Ϣ
int Show(LinkList L);
//���յ���˳������
void Sort(LinkList &L);
//�鿴��ǰ���������еĽ�����������time�Ǻ������ʱ��
int getCount(LinkList &L,int time);
//ɾ����㺯��,ɾ��p����һ�����
void Delet(LinkList &L,LinkList p);
int DecodeTime(char time[]);//����׼ʱ��ת��Ϊmin
void NowTime(int time);//�����ǰ���е�ʱ��
