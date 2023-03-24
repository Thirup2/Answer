/* 栈驱动程序 */
/* 包含头文件 */
#include "SeqStack.h"
#include <stdio.h>

/* 测试模块 */
void ShowStack(PtrStack stack);
void EatChars(void);
void Insert(PtrStack stack);
void Delete(PtrStack stack);

/* 主函数 */
int main(void)
{
    printf("请输入需要的栈长：");
    size_t size;
    scanf("%lu", &size);
    printf("开始创建栈...\n");
    PtrStack stack = InitStack(size);
    printf("创建成功！\n");
    ShowStack(stack);
    Insert(stack);
    Delete(stack);
    printf("开始清空栈...\n");
    ClearStack(stack);
    printf("清空操作结束！\n");
    ShowStack(stack);
    DestroyStack(stack);

    return 0;
}

/* 测试模块定义 */
void ShowStack(PtrStack stack)
{
    printf(">> 当前栈：\n");
    printf("    >> 是否为空：%s\n", StackEmpty(stack) ? "是" : "否");
    printf("    >> 元素个数：%lu\n", StackLenth(stack));
    printf("    >> 元素内容：");
    PrintStack(stack);
    printf("    >> 栈顶元素：");
    Status i;
    ElemType elem;
    i = GetTop(stack, &elem);
    if (i == ISEMPTY) {
        printf("无\n");
    } else {
        PrintElem(&elem);
        printf("\n");
    }
}
void EatChars(void)
{
    while (getchar() != '\n');
}
void Insert(PtrStack stack)
{
    printf("开始压栈测试...\n");
    ElemType elem;
    Status i;
    while (ReadElem(&elem)) {
        printf("开始压栈...\n");
        i = Push(stack, &elem);
        if (i == ISFULL) {
            printf("压栈失败，栈已满！\n");
            printf("即将退出压栈测试...\n");
            break;
        } else {
            printf("压栈成功！\n");
            printf("继续压栈");
            continue;
        }
    }
    EatChars();
    printf("压栈测试结束！\n");
    ShowStack(stack);
}
void Delete(PtrStack stack)
{
    printf("开始弹栈测试...\n");
    ElemType elem;
    Status i;
    printf("请输入是否进行弹栈操作(请输入yes或no): ");
    while (getchar() == 'y') {
        EatChars();
        printf("开始弹栈...\n");
        i = Pop(stack, &elem);
        if (i == ISEMPTY) {
            printf("弹栈失败，栈为空！\n");
            printf("即将退出弹栈测试...\n");
            break;
        } else {
            printf("弹栈成功！栈顶元素为：");
            PrintElem(&elem);
            printf("\n");
            printf("继续弹栈操作请选择是否进行弹栈操作(请输入yes或no): ");
            continue;
        }
    }
    EatChars();
    printf("弹栈测试结束！\n");
    ShowStack(stack);
}