/* 单链表结点类型头文件 */
#ifndef _NODE_HEAD_H_
#define _NODE_HEAD_H_

/* 包含头文件 */
#include "../../../0 Head/ElemType.h"
#include "../../../0 Head/Status.h"

/* 单链表结点类型定义 */
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

/* 单链表结点类型函数接口 */

#endif