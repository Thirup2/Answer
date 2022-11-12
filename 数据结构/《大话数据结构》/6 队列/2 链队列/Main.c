/* 循环队列驱动程序源文件Main.c, 与LinkQueue一起编译 */

/* 包含头文件 */
#include "LinkQueue.h"

/* 测试模块 */
void ShowQueue(PtrQueue queue);
void EatChars(void);
void Insert(PtrQueue queue);
void Delete(PtrQueue queue);
void Clear(PtrQueue queue);

/* 主函数 */
int main(void)
{
    PtrQueue queue = InitQueue();
    ShowQueue(queue);
    Insert(queue);
    Delete(queue);
    Clear(queue);
    DestroyQueue(queue);

    return 0;
}

/* 测试模块定义 */
void ShowQueue(PtrQueue queue)
{
    printf("现在的队列：\n");
    printf("    >> 是否为空：");
    printf("%s\n", QueueEmpty(queue) ? "是" : "否");
    printf("    >> 元素个数：%d\n", QueueLength(queue));
    printf("    >> 元素内容：");
    PrintQueue(queue);
    printf("    >> 队头元素：");
    ElemType elem;
    int r = GetHead(queue, &elem);
    if (r == -1) {
        printf("空队列\n");
    } else if (r == 0) {
        PrintElem(&elem);
        printf("\n");
    }
}
void EatChars(void)
{
    while (getchar() != '\n');
}
void Insert(PtrQueue queue)
{
    printf("开始插入...\n");
    ElemType elem;
    int r;
    printf("请输入待插入的元素（按\"x, y\"的格式）：");
    while (scanf("%d, %d", &elem.x, &elem.y) == 2) {
        EatChars();
        r = EnQueue(queue, &elem);
        if (r == -1) {
            printf("队列已满！\n");
            goto end;
        } else if (r == 0) {
            printf("插入成功！\n");
            printf("继续插入请输入待插入的元素（按\"x, y\"的格式）：");
            continue;
        }
    }
    EatChars();
end:printf("插入操作结束！\n");
    ShowQueue(queue);
}
void Delete(PtrQueue queue)
{
    printf("开始删除...\n");
    ElemType elem;
    int r;
    printf("请选择是否删除元素： y) 是      n) 否\n");
    char ch;
    while ((ch = getchar()) != EOF) {
        EatChars();
        if (ch == 'y') {
            r = DeQueue(queue, &elem);
            if (r == -1) {
                printf("队列为空！\n");
                goto end;
            } else if (r == 0) {
                printf("删除成功！被删除元素为：");
                PrintElem(&elem);
                printf("\n");
                printf("是否继续删除： y) 是      n) 否\n");
                continue;
            }
        } else if (ch == 'n') {
            goto end;
        } else {
            printf("输入格式有误，请重新输入：");
            continue;
        }
    }
    EatChars();
end:printf("删除操作结束！\n");
    ShowQueue(queue);
}
void Clear(PtrQueue queue)
{
    printf("开始清空...\n");
    ClearQueue(queue);
    printf("清空操作结束！\n");
    ShowQueue(queue);
}