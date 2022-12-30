/* 单链表类型头文件 */
#ifndef _LINKLIST_HEAD_H_
#define _LINKLIST_HEAD_H_

/* 包含头文件 */
#include "Node/Node.h"
#include "../../0 Head/Status.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 单链表类型定义 */
struct list
{
    PtrNode head;
};
typedef struct list LinkList;
typedef LinkList *PtrLL;
typedef const LinkList *cPtrLL;

/* 单链表函数接口 */

#endif