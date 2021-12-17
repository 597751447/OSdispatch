//
// Created by shijiajing on 2021/12/17.
//

#ifndef OSDISPATCH_SRTF_H
#define OSDISPATCH_SRTF_H
#pragma once
#endif //OSDISPATCH_SRTF_H
#include "../common/utils.h"
//获取剩余时间最小结点的前一个结点
LinkList Min(LinkList &L,int count);
//最短剩余时间优先算法本体
void Srtf(LinkList &L);