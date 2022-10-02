/* 顺序二叉树接口函数文件SqBiTree.c */

/* 包含头文件 */
#include "SqBiTree.h"

/* 局部函数原型 */

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素指针
*/
void PrintElem(PNode elem);

/* 数据元素处理函数定义 */

/*
** 操作: 更改数据元素的值
** 参数:
** 1. 待更改的数据元素指针
** 2. 用于更改的数据元素指针
*/
void ChangeElem(ElemType *elem1, ElemType *elem2)
{
    elem1->x = elem2->x;
    elem1->y = elem2->y;
}

/*
** 操作: 比较两个数据元素是否相同
** 参数: 用于比较的两个数据元素指针
** 返回值:
** 1. 若相同则返回true
** 2. 不相同返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2)
{
    if (elem1->x == elem2->x && elem1->y == elem2->y) {
        return true;
    }
    return false;
}

/* 顺序二叉树接口函数定义 */

/*
** 操作: 构造空树
** 返回值: 一个空树的指针
*/
SqBiTree *InitTree(void)
{
    SqBiTree *Tree = (SqBiTree *) malloc(sizeof(SqBiTree));
    Tree->tree = NULL;
    Tree->length = 0;
    return Tree;
}

/*
** 操作: 销毁树
** 参数: 待销毁的树指针
*/
void DestroyTree(SqBiTree *tree)
{
    free(tree->tree);
    free(tree);
}

/*
** 操作: 按definition的定义构造树
** 参数:
** 1. 原树的指针
** 2. definition定义
** 返回值: 新树的指针
*/
SqBiTree *CreatTree(SqBiTree *tree, Pos *position)
{
    int n = (int) pow(2, position->level - 1) - 1 + position->order;
    tree->tree = (PNode) calloc(n, sizeof(Node));
    tree->length = n;
    return tree;
}

/*
** 操作: 判断是否为空树
** 参数: 树指针
** 返回值:
** 1. 若为空返回true
** 2. 否则返回false
*/
bool TreeEmpty(SqBiTree *tree)
{
    if (tree->tree == NULL || tree->tree[0].flag == false) {
        return true;
    }
    return false;
}

/*
** 操作: 返回树的深度
** 参数: 树指针
** 返回值:
** 1. 若树为空, 则返回0
** 2. 否则返回树的深度
*/
int TreeDepth(SqBiTree *tree)
{
    return (int) log2(tree->length) + 1;
}

/*
** 操作: 返回树的根节点
** 参数: 树指针
** 返回值:
** 1. 若根节点不存在或无值则返回空指针
** 2. 否则返回根节点的指针
*/
ElemType *Root(SqBiTree *tree)
{
    return &(tree->tree[0].data);
}

/*
** 操作: 返回树中指定结点的元素值
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若结点存在且有值, 则返回结点指针
** 2. 否则返回空指针
*/
ElemType *Value(SqBiTree *tree, Pos *position)
{
    int n = (int) pow(2, position->level - 1) - 2 + position->order;
    if (n > tree->length - 1) {
        return NULL;
    }
    if (tree->tree[n].flag == false) {
        return NULL;
    }
    return &(tree->tree[n].data);
}

/*
** 操作: 为树中指定结点赋值
** 参数:
** 1. 树指针
** 2. 结点位置
** 3. 待赋的值
** 返回值:
** 1. 若结点不存在则返回-1
** 2. 否则执行操作返回0
*/
int Assign(SqBiTree *tree, Pos *position, ElemType *elem)
{
    int n = (int) pow(2, position->level - 1) - 2 + position->order;
    if (n > tree->length - 1) {
        return -1;
    }
    tree->tree[n].data.x = elem->x;
    tree->tree[n].data.y = elem->y;
    tree->tree[n].flag = true;
    return 0;
}

/*
** 操作: 返回指定结点的双亲结点
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若指定结点非根节点且其双亲结点存在且有值, 则返回其双亲结点的值
** 2. 否则返回空指针
*/
ElemType *Parent(SqBiTree *tree, Pos *position)
{
    int n = (int) pow(2, position->level - 1) - 1 + position->order;
    if (n == 1) {
        return NULL;
    }
    n /= 2;
    n--;
    if (n > tree->length - 1) {
        return NULL;
    }
    if (tree->tree[n].flag == false) {
        return NULL;
    }
    return &(tree->tree[n].data);
}

/*
** 操作: 返回指定结点的左孩子结点
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若指定结点的左孩子结点存在且有值, 则返回其左孩子结点的值
** 2. 否则返回空指针
*/
ElemType *LeftChild(SqBiTree *tree, Pos *position)
{
    int i = (int) pow(2, position->level - 1) - 1 + position->order;
    if (2 * i > tree->length) {
        return NULL;
    }
    i *= 2;
    i--;
    if (tree->tree[i].flag == false) {
        return NULL;
    }
    return &(tree->tree[i].data);
}

/*
** 操作: 返回指定结点的右兄弟结点
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若指定结点的右兄弟结点存在且有值, 则返回其左孩子结点的值
** 2. 否则返回空指针
*/
ElemType *RightSibling(SqBiTree *tree, Pos *position)
{
    int n = (int) pow(2, position->level - 1) - 1 + position->order;
    if (n + 1 > tree->length) {
        return NULL;
    }
    if (tree->tree[n].flag == false) {
        return NULL;
    }
    return &(tree->tree[n].data);
}

/*
** 操作: 层序遍历顺序二叉树
** 参数: 树指针
*/
void TraverseTree(SqBiTree *tree, void (*ElemFun)(PNode elem))
{
    int n = 0;
    for (int i = 0; i < (int) log2(tree->length) + 1; i++) {
        printf("Level %d: ", i + 1);
        for (int j = (int) pow(2, i) - 1; j < (int) pow(2, i + 1) - 1; j++) {
            n++;
            printf("[%d: ", j - (int) pow(2, i) + 2);
            ElemFun(&(tree->tree[j]));
            printf("] ");
            if (n == tree->length) {
                return;
            }
        }
        printf("\n");
    }
}

/* 局部函数定义 */

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素指针
*/
void PrintElem(PNode elem)
{
    if (elem->flag == true) {
        printf("(%d, %d)", elem->data.x, elem->data.y);
    } else {
        printf("No Data");
    }
}