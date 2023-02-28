#include "ArrayBiTree.h"
#include <stdio.h>
#include <stdlib.h>

/* 函数测试模块 */
void ShowTree(cPtrTree tree);

PtrNode GetDefinition(size_t size);

/* 主函数 */
int main(void)
{
    size_t depth;
    printf("请输入树的深度: ");
    scanf("%lu", &depth);
    PtrTree tree = InitTree(depth);
    ShowTree(tree);
    DestroyTree(tree);

    size_t size;
    printf("请输入树的结点个数: ");
    scanf("%lu", &size);
    PtrNode definition = GetDefinition(size);
    PtrTree def_tree = CreateTree(definition, size);
    ShowTree(def_tree);
    free(definition);

    ElemType elem;
    Pos pos;
    PtrPos cur_e;
    printf("请输入一个结点位置(level, order)：");
    scanf("%lu, %lu", &pos.level, &pos.order);

    // 根结点
    cur_e = Root(def_tree);
    if (!cur_e) {
        printf("无根结点！\n");
    } else {
        Value(def_tree, cur_e, &elem);
        printf("根结点的值为：");
        PrintElem(&elem);
        printf("\n");
        printf("请输入你想要修改的值：");
        if (ReadElem(&elem)) {
            Assign(def_tree, cur_e, &elem);
        }
    }
    ShowTree(def_tree);
    free(cur_e);

    // 双亲
    cur_e = Parent(def_tree, &pos);
    if (!cur_e) {
        printf("无双亲！\n");
    } else {
        Value(def_tree, cur_e, &elem);
        printf("双亲结点的值为：");
        PrintElem(&elem);
        printf("\n");
        printf("请输入你想要修改的值：");
        if (ReadElem(&elem)) {
            Assign(def_tree, cur_e, &elem);
        }
    }
    ShowTree(def_tree);
    free(cur_e);

    // 左孩子
    cur_e = LeftChild(def_tree, &pos);
    if (!cur_e) {
        printf("无左孩子！\n");
    } else {
        Value(def_tree, cur_e, &elem);
        printf("左孩子结点的值为：");
        PrintElem(&elem);
        printf("\n");
        printf("请输入你想要修改的值：");
        if (ReadElem(&elem)) {
            Assign(def_tree, cur_e, &elem);
        }
    }
    ShowTree(def_tree);
    free(cur_e);

    // 右兄弟
    cur_e = RightSibling(def_tree, &pos);
    if (!cur_e) {
        printf("无右兄弟！\n");
    } else {
        Value(def_tree, cur_e, &elem);
        printf("右兄弟结点的值为：");
        PrintElem(&elem);
        printf("\n");
        printf("请输入你想要修改的值：");
        if (ReadElem(&elem)) {
            Assign(def_tree, cur_e, &elem);
        }
    }
    ShowTree(def_tree);
    free(cur_e);

    ClearTree(def_tree);
    ShowTree(def_tree);

    DestroyTree(def_tree);
    return 0;
}

/* 测试模块定义 */
void ShowTree(cPtrTree tree)
{
    printf(">> 当前的树：\n");
    printf("    >> 是否为空：%s\n", TreeEmpty(tree) ? "是" : "否");
    printf("    >> 树的深度：%lu\n", TreeDepth(tree));
    printf("    >> 前序遍历：");
    PrintTree(tree, PreOrder);
    printf("    >> 中序遍历：");
    PrintTree(tree, InOrder);
    printf("    >> 后序遍历：");
    PrintTree(tree, PostOrder);
    printf("    >> 层序遍历：");
    PrintTree(tree, LevelOrder);
}

PtrNode GetDefinition(size_t size)
{
    PtrNode definition = (PtrNode) malloc(size * sizeof(Node));
    if (!definition) {
        exit(EXIT_FAILURE);
    }
    ElemType elem;
    for (size_t i = 0; i < size; i++) {
        if (ReadElem(&elem)) {
            AssignElem(&(definition[i].data), &elem);
            definition[i].used = true;
        } else {
            definition[i].used = false;
        }
    }
    return definition;
}