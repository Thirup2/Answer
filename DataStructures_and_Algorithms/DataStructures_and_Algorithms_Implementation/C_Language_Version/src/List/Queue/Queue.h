#ifndef QUEUE_H_
#define QUEUE_H_

#define STDOUT false
#define STDIN false

// 如果要测试不同实现方式的队列，则修改下方的 #define
// 并将 CMakeLists.txt 中的库依赖修改为目标链接库
#define LQUEUE

#ifdef CQUEUE
#include "CycleQueue.h"
#else
#ifdef LQUEUE
#include "LinkQueue.h"
#endif // LQUEUE
#endif // CQUEUE

#endif