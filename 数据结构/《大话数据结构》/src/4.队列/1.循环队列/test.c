/* 队列驱动程序 */
/* 包含头文件 */
#include "RoundRobinQueue.h"
#include <stdio.h>

/* 测试模块 */
void ShowQueue(PtrQueue queue);
void EatChars(void);
void Insert(PtrQueue queue);
void Delete(PtrQueue queue);

/* 主函数 */
int main(void)
{
    printf("请输入需要的队列大小：");
    size_t size;
    scanf("%lu", &size);
    printf("开始创建队列...\n");
    PtrQueue queue = InitQueue(size);
    printf("创建成功!\n");
    ShowQueue(queue);
    Insert(queue);
    Delete(queue);
    Insert(queue);
    Delete(queue);
    printf("开始清空队列...\n");
    ClearQueue(queue);
    ShowQueue(queue);
    printf("测试结束！\n");
    DestroyQueue(queue);

    return 0;
}

/* 测试模块定义 */
void ShowQueue(PtrQueue queue)
{
    printf(">> 当前队列：\n");
    printf("    >> 是否为空：%s\n", QueueEmpty(queue) ? "是" : "否");
    printf("    >> 元素个数：%lu\n", QueueLength(queue));
    printf("    >> 队列内容：");
    PrintQueue(queue);
    printf("    >> 队头元素：");
    Status i;
    ElemType elem;
    i = GetHead(queue, &elem);
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
void Insert(PtrQueue queue)
{
    printf("开始入队列测试...\n");
    Status i;
    ElemType elem;
    while (ReadElem(&elem)) {
        printf("开始插入...\n");
        i = EnQueue(queue, &elem);
        if (i == ISFULL) {
            printf("插入失败，队列已满！\n");
            printf("即将退出测试...\n");
            break;
        } else {
            printf("插入成功！");
            printf("继续插入");
            continue;
        }
    }
    EatChars();
    printf("插入操作结束！\n");
    ShowQueue(queue);
}
void Delete(PtrQueue queue)
{
    printf("开始出队列测试...\n");
    Status i;
    ElemType elem;
    printf("请选择是否进行出队列操作(请输入yes或no): ");
    while (getchar() == 'y') {
        EatChars();
        printf("开始删除...\n");
        i = DeQueue(queue, &elem);
        if (i == ISEMPTY) {
            printf("删除失败，队列为空！\n");
            printf("即将退出测试...\n");
            break;
        } else {
            printf("删除成功！被删除的元素是：");
            PrintElem(&elem);
            printf("\n");
            printf("请选择是否继续出队列操作(请输入yes或no): ");
            continue;
        }
    }
    EatChars();
    printf("删除操作结束！\n");
    ShowQueue(queue);
}