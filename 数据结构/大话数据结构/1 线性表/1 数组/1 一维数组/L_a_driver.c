/* 一维数组驱动程序源文件L_a_driver.c */
/* 和Linear_array.c一起编译 */
#include "Linear_Array.h"
#include <stdio.h>
#include <stdlib.h>

int change_value(L_Array *parr, int i, ElemType elem, ElemType *de_elem);
void start(L_Array *parr);
void insert(L_Array *parr);
void delete(L_Array *parr);
void change(L_Array *parr);
void search(L_Array *parr);
void reset(L_Array *parr);
void access(void);
void show_arr(L_Array arr);
void skip(void);

int main(void)
{
    printf("1. 创建数组\n");
    access();
    printf("开始创建...\n");
    L_Array arr;
    L_Array *parr = &arr;
    printf("创建成功!\n");
    start(parr);
    insert(parr);
    delete(parr);
    change(parr);
    search(parr);
    reset(parr);

    return 0;
}
void skip(void)
{
    while (getchar() != '\n') {
        continue;
    }
}
void show_arr(L_Array arr)
{
    printf("现在的数组:\n");
    printf("    1) 是否为空: ");
    if (ArrayEmpty(arr)) {
        printf("是\n");
    } else {
        printf("否\n");
    }
    printf("    2) 元素个数: %d\n", ArrayLength(arr));
    printf("    3) 数组元素: ");
    ArrayTraverse(arr);
}
void access(void)
{
    printf("请按任意键继续...\n");
    getchar();
}
int change_value(L_Array *parr, int i, ElemType elem, ElemType *de_elem)
{
    int r;
    r = ArrayDelete(parr, i, de_elem);
    if (!r) {
        return -1;      // 修改位置不合理
    }
    ArrayInsert(parr, i, elem);
    return 0;     // 返回被修改元素值
}
void start(L_Array *parr)
{
    access();
    printf("2. 初始化\n");
    access();
    printf("是否进行初始化?\ny): 是     n):否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        skip();
        switch (ch) {
            case 'y':
                printf("开始初始化...\n");
                InitArray(parr);
                printf("初始化完成!\n");
                break;
            case 'n':
                break;
            default:
                printf("输入格式错误, 请重新输入: ");
                continue;;
        }
        break;
    }
    printf("操作结束!\n");
    access();
    show_arr(*parr);
}
void insert(L_Array *parr)
{
    access();
    printf("3. 插入\n");
    access();
    printf("请选择插入方法: \n");
    printf("a) 顺序插入     b) 自由插入\n");
    int ch;
    int count;
    int start;
    int i;
    int r;
    ElemType elem;
    while ((ch = getchar()) != EOF) {
        skip();
        switch (ch) {
            case 'a':
start1: printf("请输入您要插入的元素个数: ");
                scanf("%d", &count);
                printf("请输入您想要插入元素的位置: ");
                scanf("%d", &i);
                printf("请输入您第一个想要插入的元素的值: ");
                scanf("%d", &start);
                printf("开始插入...\n");
                for (int k = i; k < i + count; ++k) {
                    r = ArrayInsert(parr, k, start + k - i);
                    if (r == -1) {
                        printf("数组已满, 无法继续插入!\n");
                        goto end1;
                    } else if (r == -2) {
                        printf("插入位置不合理, 请重新输入...\n");
                        goto start1;
                    }
                }
                printf("插入成功!\n");
end1: break;
            case 'b':
start2: printf("请输入您想要插入的位置: ");
                while (scanf("%d", &i) == 1) {
                    printf("请输入您想要插入的元素: ");
                    scanf("%d", &elem);
                    printf("开始插入...\n");
                    r = ArrayInsert(parr, i, elem);
                    if (r == -1) {
                        printf("数组已满, 无法继续插入!\n");
                        goto end2;
                    } else if (r == -2) {
                        printf("插入位置不合理, 请重新输入...\n");
                        goto start2;
                    } else {
                        printf("插入成功!\n若想继续插入, 则请输入您想插入的位置, 否则请按q: ");
                    }
                }
end2: break;
            default:
                printf("输入格式错误, 请重新输入: ");
                continue;
        }
        break;
    }
    skip();
    printf("操作结束!\n");
    access();
    show_arr(*parr);
}
void delete(L_Array *parr)
{
    access();
    printf("4. 删除数据\n");
    access();
    int i;
    int r;
    ElemType elem;
    printf("请输入您想要删除的元素的位序: ");
    while (scanf("%d", &i) == 1) {
        printf("开始删除...\n");
        r = ArrayDelete(parr, i, &elem);
        if (r == false) {
            printf("删除位置不合理, 请重新输入您想要删除的元素的位序(按q退出): ");
            continue;
        } else {
            printf("删除成功!\n您删除的元素是: %d\n", elem);
            printf("如果想继续删除, 请输入元素位序, 否则请按q退出: ");
        }
    }
    skip();
    printf("操作结束!\n");
    access();
    show_arr(*parr);
}
void change(L_Array *parr)
{
    access();
    printf("5. 更改数据\n");
    access();
    int i;
    int r;
    ElemType elem;
    ElemType de_elem;
    printf("请输入您想要更改的元素位序: ");
    while (scanf("%d", &i) == 1) {
        printf("请输入您想要更改的元素值: ");
        scanf("%d", &elem);
        printf("开始更改...\n");
        r = change_value(parr, i, elem, &de_elem);
        if (r == -1) {
            printf("修改位置不合理, 请重新输入(按q退出): ");
        } else {
            printf("修改成功!\n");
            printf("%d修改为%d\n", de_elem, elem);
            printf("若想继续修改, 请输入想要修改的元素位序(按q退出): ");
        }
    }
    skip();
    printf("操作结束!\n");
    access();
    show_arr(*parr);
}
void search(L_Array *parr)
{
    access();
    printf("6. 搜索\n");
    access();
    printf("请选择按照下面哪种方式进行搜索:\n");
    printf("a) 按序搜索     b) 按值搜索\n");
    int ch;
    ElemType elem;
    int i;
    int r;
    while ((ch = getchar()) != EOF) {
        skip();
        switch (ch) {
            case 'a':
                printf("请输入您要查找的位序: ");
                while (scanf("%d", &i) == 1) {
                    printf("开始搜索...\n");
                    r = GetElem(*parr, i, &elem);
                    if (r == -2) {
                        printf("待搜索位置不合理, 请重新输入(按q退出): ");
                    } else if (r == -1) {
                        printf("该位置元素不存在, 请重新输入(按q退出): ");
                    } else {
                        printf("搜索完成!\n");
                        printf("位于第%d个位序的元素是: %d\n", i, elem);
                        printf("若想继续搜索, 请输入您要查找的位序(按q退出): ");
                    }
                }
                break;
            case 'b':
                printf("请输入您要查找的元素: ");
                while (scanf("%d", &elem) == 1) {
                    printf("开始搜索...\n");
                    r = LocateElem(*parr, elem);
                    if (!r) {
                        printf("该元素不存在, 请重新输入(按q退出): ");
                    } else {
                        printf("搜索完成!\n");
                        printf("元素%d的位序是: %d\n", elem, r);
                        printf("若想继续搜索, 请输入您要查找的元素(按q退出): ");
                    }
                }
                break;
            default:
                printf("您的输入格式不正确, 请重新输入: ");
                continue;
        }
        break;
    }
    skip();
    printf("操作结束!\n");
    access();
    show_arr(*parr);
}
void reset(L_Array *parr)
{
    access();
    printf("7. 重置\n");
    access();
    printf("请选择是否充值数组: \n");
    printf("y) 是       n) 否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        skip();
        switch (ch) {
            case 'y':
                printf("开始重置...\n");
                ClearArray(parr);
                printf("重置成功!\n");
                break;
            case 'n':
                break;
            default:
                printf("您的输入格式不正确, 请重新输入: ");
                continue;
        }
        break;
    }
    printf("操作结束!\n");
    access();
    show_arr(*parr);
}