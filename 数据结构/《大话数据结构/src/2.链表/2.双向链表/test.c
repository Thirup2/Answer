/* 链表类型驱动程序 */

/* 包含头文件 */
#include "DoubleLinkList.h"
#include <stdio.h>

/* 测试模块函数原型 */
void ShowList(cPtrLL list);
void Insert(PtrLL list);
void Find(cPtrLL list);
void Search(cPtrLL list);
void Delete(PtrLL list);
void EatChars(void);

/* 主函数 */
int main(void)
{
    printf("开始创建链表...\n");
    PtrLL list = InitList();
    printf("创建成功！\n");
    ShowList(list);
    Insert(list);
    Find(list);
    Search(list);
    Delete(list);
    Find(list);
    Search(list);

    printf("开始清空链表...\n");
    ClearList(list);
    printf("清空完成！\n");
    ShowList(list);
    DestroyList(list);

    return 0;
}

/* 测试模块函数定义 */
void ShowList(cPtrLL list)
{
    printf(">> 现在的数组：\n");
    printf("    >> 是否为空：");
    printf("%s\n", ListEmpty(list) ? "是" : "否");
    printf("    >> 元素个数：%lu\n", ListLength(list));
    printf("    >> 元素内容：");
    PrintList(list);
}
void Insert(PtrLL list)
{
    printf("现在开始插入元素测试...\n");
    size_t position;
    ElemType elem;
    Status r;
    printf("请输入要插入的元素位置：");
    while (scanf("%lu", &position) == 1) {
        if (ReadElem(&elem)) {
            printf("开始插入...\n");
            r = ListInsert(list, position, &elem);
            if (r == WRONGPOS) {
                printf("插入失败，位序不合理！\n");
                printf("请重新输入插入元素位序：");
                continue;
            } else {
                printf("插入成功！\n");
                printf("继续插入请输入位序：");
                continue;
            }
        }
    }
    EatChars();
    printf("插入元素测试完毕！\n");
    ShowList(list);
}
void Find(cPtrLL list)
{
    printf("开始访问元素测试...\n");
    size_t position;
    ElemType elem;
    Status r;
    printf("请输入待访问元素位序：");
    while (scanf("%lu", &position) == 1) {
        printf("开始访问元素...\n");
        r = GetElem(list, position, &elem);
        if (r == ISEMPTY) {
            printf("链表为空，访问失败！\n");
            printf("即将退出测试...\n");
            break;
        } else if (r == WRONGPOS) {
            printf("位序不合理，访问失败！\n");
            printf("请重新输入待访问位序：");
            continue;
        } else {
            printf("访问成功！您所访问的元素是：");
            PrintElem(&elem);
            printf("\n");
            printf("继续访问请输入待访问位序：");
            continue;
        }
    }
    EatChars();
    printf("访问元素完毕！\n");
    ShowList(list);
}
void Search(cPtrLL list)
{
    printf("开始查找元素测试...\n");
    ElemType elem;
    size_t i;
    while (ReadElem(&elem)) {
        printf("开始查找...\n");
        i = LocateElem(list, &elem);
        if (i == 0) {
            printf("元素不存在！\n");
            printf("继续查找");
            continue;
        } else {
            printf("查找成功！您查找的元素所在的位序是：%lu\n", i);
            printf("继续查找");
        }
    }
    EatChars();
    printf("查找元素完毕！\n");
    ShowList(list);
}
void Delete(PtrLL list)
{
    printf("开始删除元素测试...\n");
    size_t position;
    ElemType elem;
    Status r;
    printf("请输入要删除的元素位序：");
    while (scanf("%lu", &position) == 1) {
        printf("开始删除...\n");
        r = ListDelete(list, position, &elem);
        if (r == ISEMPTY) {
            printf("链表为空，删除失败！\n");
            printf("即将退出测试...\n");
            break;
        } else if (r == WRONGPOS) {
            printf("位序不合理，删除失败！\n");
            printf("请重新输入待删除元素位序：");
            continue;
        } else {
            printf("删除成功！您删除的元素是：");
            PrintElem(&elem);
            printf("\n");
            printf("继续删除请输入待删除位序：");
            continue;
        }
    }
    printf("删除元素完毕！\n");
    EatChars();
    ShowList(list);
}
void EatChars(void)
{
    while (getchar() != '\n');
}