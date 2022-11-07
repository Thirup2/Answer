/* 两栈共享空间驱动程序文件Main.c, 和SqDulStack一起编译 */

/* 包含头文件 */
#include "SqDulStack.h"

/* 测试模块 */
void ShowStack(PtrStack stack);
void EatChar(void);
void Insert(PtrStack stack);
void Delete(PtrStack stack);
void Find(PtrStack stack);

/* 主函数 */

int main(void)
{
    int size;
    scanf("%d", &size);
    EatChar();
    PtrStack stack = InitStack(size);
    ShowStack(stack);
    Insert(stack);
    Delete(stack);
    Find(stack);
    ClearStack(stack,STACK1);
    ClearStack(stack, STACK2);
    ShowStack(stack);
    DestroyStack(stack);

    return 0;
}

/* 测试模块定义 */

void ShowStack(PtrStack stack)
{
    printf("现在的栈:\n");
    printf("    >> 栈1:\n");
    printf("    >> 是否为空: ");
    printf("%s\n", StackEmpty(stack, STACK1) ? "是" : "否");
    printf("    >> 元素个数: ");
    printf("%d\n", StackLength(stack, STACK1));
    printf("    >> 元素内容: ");
    PrintStack(stack, STACK1);
    printf("    >> 栈2:\n");
    printf("    >> 是否为空: ");
    printf("%s\n", StackEmpty(stack, STACK2) ? "是" : "否");
    printf("    >> 元素个数: ");
    printf("%d\n", StackLength(stack, STACK2));
    printf("    >> 元素内容: ");
    PrintStack(stack, STACK2);
}
void EatChar(void)
{
    while (getchar() != '\n');
}
void Insert(PtrStack stack)
{
    printf("开始插入...\n");
    printf("请选择要插入的栈: 1) 栈1   2) 栈2   q) 退出\n");
    int choice;
    ElemType elem;
    int r;
    while (scanf("%d", &choice) == 1) {
        EatChar();
        if (choice == STACK1 || choice == STACK2) {
            printf("请输入要插入的元素(按\"x, y\"的格式): ");
            while (scanf("%d, %d", &elem.x, &elem.y) == 2) {
                EatChar();
                r = Push(stack, choice, &elem);
                if (r == -1) {
                    printf("栈已满!\n");
                    goto end;
                } else if (r == 0) {
                    printf("插入成功!\n");
                    printf("继续插入请输入要插入的元素, 否则请按q: ");
                    continue;
                }
            }
            EatChar();
        } else {
            printf("输入不合理, 请重新输入: ");
            continue;
        }
        printf("继续插入请选择栈序, 否则请按q: ");
    }
    EatChar();
end:printf("插入操作结束!\n");
    ShowStack(stack);
}
void Delete(PtrStack stack)
{
    printf("开始删除...\n");
    printf("请选择栈: 1) 栈1    2) 栈2     q) 退出\n");
    int choice;
    ElemType elem;
    int r;
    while (scanf("%d", &choice) == 1) {
        EatChar();
        if (choice == STACK1 || choice == STACK2) {
            r = Pop(stack, choice, &elem);
            if (r == -1) {
                printf("栈为空!\n");
                goto end;
            } else if (r == 0) {
                printf("删除成功, 你删除的元素是: (%d, %d)\n", elem.x, elem.y);
                printf("继续删除请选择栈: ");
                continue;
            }
        } else {
            printf("输入不合理, 请重新输入: ");
            continue;
        }
    }
    EatChar();
end:printf("删除操作结束!\n");
    ShowStack(stack);
}
void Find(PtrStack stack)
{
    ElemType elem;
    int r;
    printf("开始查找栈顶元素...\n");
    r = GetTop(stack, STACK1, &elem);
    printf("栈1: ");
    if (r == -1) {
        printf("无元素\n");
    } else {
        printf("(%d, %d)\n", elem.x, elem.y);
    }
    r = GetTop(stack, STACK2, &elem);
    printf("栈2: ");
    if (r == -1) {
        printf("无元素\n");
    } else {
        printf("(%d, %d)\n", elem.x, elem.y);
    }
}