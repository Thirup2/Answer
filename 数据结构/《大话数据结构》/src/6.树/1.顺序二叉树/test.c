#include "ArrayBiTree.h"
#include <stdio.h>

/* 函数测试模块 */
void ShowTree(cPtrTree tree);

/* 主函数 */
int main(void)
{
    size_t size;
    printf("请输入需要的二叉树的深度\n");
    scanf("%lu", &size);
    PtrTree tree = InitTree(size);
    ShowTree(tree);

    DestroyTree(tree);
    return 0;
}

/* 测试模块定义 */
void ShowTree(cPtrTree tree)
{
    printf(">> 当前的二叉树:\n");
    printf("    >> 是否为空：%s\n", TreeEmpty(tree)?"是":"否");
    printf("    >> 树的深度：%lu\n", TreeDepth(tree));
    printf("    >> 前序遍历：");
    PrintTree(tree, PreOrder);
    printf("\n");
    printf("    >> 中序遍历：");
    PrintTree(tree, InOrder);
    printf("\n");
    printf("    >> 后序遍历：");
    PrintTree(tree, PostOrder);
    printf("\n");
    printf("    >> 层序遍历：");
    PrintTree(tree, LevelOrder);
    printf("\n");
}