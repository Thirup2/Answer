#ifndef STACK_H_
#define STACK_H_

#define STDOUT false
#define STDIN false

// 如果要测试不同实现方式的栈，则修改下方的 #define
// 并将 CMakeListx.txt 中的库依赖修改为目标链接库
#define LSTACK

#ifdef SSSTACK
#include "StaticSeqStack.h"
#else
#ifdef DSSTACK
#include "DynamicSeqStack.h"
#else
#ifdef LSTACK
#include "LinkStack.h"
#endif // LSTACK
#endif // DSSTACK
#endif // SSSTACK

#endif