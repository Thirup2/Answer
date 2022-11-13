/* 顺序栈测试程序文件Main.c, 和SqStack.c一起编译 */

/* 包含头文件 */
#include "SqStack.h"

/* 顺序栈测试模块函数原型 */

void ShowStack(PtrStack stack);
void Insert(PtrStack stack);
void Delete(PtrStack stack);
void Get(PtrStack stack);
void EatChar(void);

/* 主函数 */

int main(void)
{
    PtrStack stack = InitStack();
    ShowStack(stack);
    Insert(stack);
    Get(stack);
    Delete(stack);
    Get(stack);
    ClearStack(stack);
    ShowStack(stack);
    DestroyStack(stack);

    return 0;
}

/* 顺序栈测试模块函数定义 */

void ShowStack(PtrStack stack)
{
    printf("现在的栈: \n");
    printf("    >> 是否为空: ");
    printf("%s\n", StackEmpty(stack) ? "是" : "否");
    printf("    >> 元素个数: ");
    printf("%d\n", StackLength(stack));
    printf("    >> 元素内容: ");
    PrintStack(stack);
}

void Insert(PtrStack stack)
{
    printf("开始插入操作...\n");
    printf("请输入一个数据元素(按\"x, y\"的格式): ");
    ElemType elem;
    int r;
    while (scanf("%d, %d", &elem.x, &elem.y) == 2) {
        EatChar();
        r = Push(stack, &elem);
        if (r == -1) {
            printf("栈已满!\n");
            break;
        } else if (r == 0) {
            printf("插入成功!\n");
            printf("继续插入请输入一个数据元素(按\"x, y\"的格式): ");
        }
    }
    EatChar();
    printf("插入操作结束!\n");
    ShowStack(stack);
}
void Delete(PtrStack stack)
{
    printf("开始删除操作...\n");
    printf("是否进行删除操作: y) 是   n) 否\n");
    char ch;
    int r;
    ElemType elem;
    while ((ch = getchar()) != EOF) {
        EatChar();
        if (ch == 'y') {
            r = Pop(stack, &elem);
            if (r == -1) {
                printf("栈为空!\n");
                break;
            } else if (r == 0) {
                printf("删除成功!\n");
                printf("是否继续删除: y) 是   n) 否\n");
                continue;
            }
        } else if (ch == 'n') {
            break;
        } else {
            printf("您的输入不合理, 请重新输入: ");
            continue;
        }
    }
    printf("删除操作结束!\n");
    ShowStack(stack);
}
void Get(PtrStack stack)
{
    printf("栈顶元素: ");
    ElemType elem;
    int r;
    r = GetTop(stack, &elem);
    if (r == -1) {
        printf("栈为空\n");
    } else if (r == 0) {
        PrintElem(&elem);
        printf("\n");
    }
}
void EatChar(void)
{
    while (getchar() != '\n') {
        continue;
    }
}