#ifndef LIST_H_
#define LIST_H_

#define STDOUT false
#define STDIN false

// 如果要测试不同实现方式的线性表，则修改下方的 #define
// 并将 CMakeListx.txt 中的库依赖修改为目标链接库
#define SSLIST

#ifdef SSLIST
#include "StaticSeqList.h"
#else
#ifdef DSLIST
#include "DynamicSeqList.h"
#else
#ifdef SLLIST
#include "SingleLinkList.h"
#else
#ifdef DLLIST
#include "DoubleLinkList.h"
#else
#ifdef CLLIST
#include "CycleLinkList.h"
#else
#ifdef DCLLIST
#include "DoubleCycleLinkList.h"
#endif // DCLLIST
#endif // CLLIST
#endif // DLLIST
#endif // SLLIST
#endif // DSLIST
#endif // SSLIST

#endif