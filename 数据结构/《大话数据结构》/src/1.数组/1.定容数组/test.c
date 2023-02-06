/* 数组驱动程序 */

/* 包含头文件 */
#include "ConstVolArray.h"
#include <stdio.h>

/* 测试模块 */
void ShowArray(PtrArray array);
void Insert(PtrArray array);
void Delete(PtrArray array);
void Get(PtrArray array);
void Locate(PtrArray array);
void Clear(PtrArray array);

void EatChars(void);

/* 主函数模块 */
int main(void)
{
    size_t size;
    printf("请输入您想要创建的数组大小：");
    scanf("%lu", &size);
    PtrArray array = InitArray(size);
    ShowArray(array);
    Insert(array);
    Get(array);
    Locate(array);
    Delete(array);
    Get(array);
    Locate(array);
    Clear(array);
    DestroyArray(array);

    return 0;
}

/* 测试模块 */
void ShowArray(PtrArray array)
{
    printf(">> 当前数组：\n");
    printf("    >> 是否为空：");
    printf("%s\n", ArrayEmpty(array) ? "是" : "否");
    printf("    >> 元素个数：%lu\n", ArrayLength(array));
    printf("    >> 元素内容：");
    PrintArray(array);
}
void Insert(PtrArray array)
{
    printf("开始插入测试...\n");
    size_t position;
    ElemType elem;
    Status r;
    printf("请输入要插入的位置：");
    while (scanf("%lu", &position) == 1) {
        if (ReadElem(&elem)) {
            printf("开始插入...\n");
            r = ArrayInsert(array, position, &elem);
            if (r == ISFULL) {
                printf("插入失败！\n数组已满，即将退出...\n");
                break;
            } else if (r == WRONGPOS) {
                printf("插入位置不合理，请重新输入：");
                continue;
            } else {
                printf("插入成功！\n继续插入请输入插入位置：");
                continue;
            }
        } else {
            break;
        }
    }
    EatChars();
    printf("插入测试结束！\n");
    ShowArray(array);
}
void Delete(PtrArray array)
{
    printf("开始删除测试...\n");
    size_t position;
    ElemType elem;
    Status r;
    printf("请输入要删除的位置：");
    while (scanf("%lu", &position) == 1) {
        printf("开始删除...\n");
        r = ArrayDelete(array, position, &elem);
        if (r == ISEMPTY) {
            printf("删除失败！\n数组为空，即将退出...\n");
            break;
        } else if (r == WRONGPOS) {
            printf("删除位置不合理，请重新输入：");
            continue;
        } else {
            printf("删除成功！\n");
            printf("你删除的元素是：");
            PrintElem(&elem);
            printf("\n");
            printf("继续删除请输入删除位置：");
            continue;
        }
    }
    EatChars();
    printf("删除测试结束！\n");
    ShowArray(array);
}
void Get(PtrArray array)
{
    printf("开始查找元素测试...\n");
    size_t position;
    ElemType elem;
    Status r;
    printf("请输入要查找的位置：");
    while (scanf("%lu", &position) == 1) {
        printf("开始查找...\n");
        r = GetElem(array, position, &elem);
        if (r == WRONGPOS) {
            printf("查询位置不合理，请重新输入：");
            continue;
        } else if (r == NOVALUE) {
            printf("查询成功！\n该位置无值\n");
            printf("继续查询请输入查询位置：");
            continue;
        } else if (r == ISEMPTY) {
            printf("查询失败！\n数组为空，即将退出...\n");
            break;
        } else {
            printf("查询成功！\n");
            printf("该位置的元素是：");
            PrintElem(&elem);
            printf("\n");
            printf("继续查询请输入查询位置：");
            continue;
        }
    }
    EatChars();
    printf("查找元素测试结束！\n");
    ShowArray(array);
}
void Locate(PtrArray array)
{
    printf("开始查找位置测试...\n");
    size_t i;
    ElemType elem;
    while (ReadElem(&elem)) {
        printf("开始查找...\n");
        i = LocateElem(array, &elem);
        if (i == 0) {
            printf("查找完成！\n该元素不存在，继续查找");
            continue;
        } else {
            printf("查找完成！\n该元素在数组的第 %lu 个位置\n", i);
            printf("继续查找");
            continue;
        }
    }
    EatChars();
    printf("查找位置测试结束！\n");
    ShowArray(array);
}
void Clear(PtrArray array)
{
    printf("开始清空数组测试...\n");
    printf("开始清空...\n");
    ClearArray(array);
    printf("清空完成！\n");
    ShowArray(array);
}

void EatChars(void)
{
    while (getchar() != '\n');
}