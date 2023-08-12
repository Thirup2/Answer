#ifndef LIST_H_
#define LIST_H_

// 如果要测试不同实现方式的线性表，则修改下方的 #define
// 并将 CMakeListx.txt 中的库依赖修改为目标链接库
#define SLLIST

#ifdef SSLIST
#include "StaticSeqList.h"
#else
#ifdef DSLIST
#include "DynamicSeqList.h"
#else
#ifdef SLLIST
#include "SingleLinkList.h"
#endif // SLLIST
#endif // DSLIST
#endif // SSLIST

#endif