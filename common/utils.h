//
// Created by shijiajing on 2021/12/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef OSDISPATCH_UTILS_H
#define OSDISPATCH_UTILS_H

#endif //OSDISPATCH_UTILS_H

struct PCB //PCB结构体
{
    char name[20];       //进程名
    char codeTime[20];
    int Arrive_Time;     //到达时间
    int Serve_Time;      //服务时间
    //int Finish_Time;     //完成时间
    int priority;        //优先级
};
typedef struct LNode            //链表结点定义
{
    PCB data;
    struct LNode *next;
}LNode,*LinkList;
//利用尾插法创建进程
int Create(LinkList &L);
//输出进程信息
int Show(LinkList L);
//按照到达顺序排序
void Sort(LinkList &L);
//查看当前就绪队列中的进程数，其中time是宏观运行时间
int getCount(LinkList &L,int time);
//删除结点函数,删除p的下一个结点
void Delet(LinkList &L,LinkList p);
int DecodeTime(char time[]);//将标准时间转换为min
char* CodeTime(int time);//将时间编码成标准形式
