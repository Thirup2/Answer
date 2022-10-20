/* 一维数组测试程序Main.c, 和Array.c一起编译 */

/* 包含头文件 */
#include "Array.h"

/* 测试模块函数原型 */

void Insert(PArray array);
void Delete(PArray array);
void Locate(PArray array);
void FindI(PArray array);
void ShowArray(PArray array);
void GetChar(void);
void EatChars(void);

/* 主函数 */
int main(void)
{
    PArray array = InitArray();
    ShowArray(array);
    Insert(array);
    Delete(array);
    Locate(array);
    FindI(array);
    ClearArray(array);
    ShowArray(array);
    DestroyArray(array);

    return 0;
}

/* 测试模块函数定义 */

void Insert(PArray array)
{
    GetChar();
    printf("接下来进行插入测试...\n");
    ElemType elem;
    int i;
    int r;
    printf("请输入要插入的位序(按q退出): ");
    while (scanf("%d", &i) == 1) {
        EatChars();
        ScanElem(&elem);
        EatChars();
        r = ArrayInsert(array, i, &elem);
        if (r == 1) {
            printf("插入位置不合理, 请重新输入(按q退出): ");
        } else if (r == -1) {
            printf("空间申请失败!\n");
            break;
        } else {
            printf("插入成功! 继续插入请输入位序, 否则请按q: ");
        }
    }
    printf("插入操作结束!\n");
    ShowArray(array);
}

void Delete(PArray array)
{
    GetChar();
    printf("接下来进行删除测试...\n");
    ElemType elem;
    int i;
    int r;
    printf("请输入要删除的位序(按q退出): ");
    while (scanf("%d", &i) == 1) {
        EatChars();
        r = ArrayDelete(array, i, &elem);
        if (r == -1) {
            printf("数组为空!\n");
            break;
        } else if (r == 1) {
            printf("删除位置不合理, 请重新输入(按q退出): ");
        } else {
            printf("删除成功, 删除的元素是(%d, %d)\n", elem.x, elem.y);
            printf("继续删除请输入位序, 否则请按q: ");
        }
    }
    printf("删除操作结束!\n");
    ShowArray(array);
}

void Locate(PArray array)
{
    GetChar();
    printf("接下来进行定位测试...\n");
    ElemType elem;
    int i;
    printf("请输入要查找的元素(以\"x, y\"的格式): ");
    while (scanf("%d, %d", &elem.x, &elem.y) == 2) {
        EatChars();
        i = LocateElem(array, &elem);
        if (i == -1) {
            printf("数组为空\n");
            break;
        } else if (i == 0) {
            printf("该元素不存在, 继续查找请输入元素(以\"x, y\"的格式): ");
        } else {
            printf("查找成功, 该元素位序为: %d\n", i);
            printf("继续查找请输入元素(以\"x, y\"的格式): ");
        }
    }
    printf("定位操作结束!\n");
    ShowArray(array);
}

void FindI(PArray array)
{
    GetChar();
    printf("接下来进行查找测试...\n");
    ElemType elem;
    int i;
    int r;
    printf("请输入想查找的元素位置(按q退出): ");
    while (scanf("%d", &i) == 1) {
        EatChars();
        r = GetElem(array, i, &elem);
        if (r == -1) {
            printf("数组为空!\n");
            break;
        } else if (r == 1) {
            printf("查找位置不合理, 请重新输入(按q退出): ");
        } else {
            printf("查找成功, 位序%d的元素为(%d, %d)\n", i, elem.x, elem.y);
            printf("继续查找请输入位序, 否则请按q: ");
        }
    }
    printf("查找操作结束!\n");
    ShowArray(array);
}

void ShowArray(PArray array)
{
    printf("当前数组: \n");
    printf("    >> 数组是否为空: ");
    if (ArrayEmpty(array)) {
        printf("是\n");
    } else {
        printf("否\n");
    }
    printf("    >> 元素个数: ");
    printf("%d\n", ArrayLength(array));
    printf("    >> 元素内容: ");
    for (int i = 1; i <= array->length; i++) {
        PrintElem(&(array->data[i]));
    }
    printf("\n");
}

void GetChar(void)
{
    EatChars();
    printf("请按回车继续...");
    getchar();
    EatChars();
}

void EatChars(void)
{
    while (getchar() != '\n') {
        continue;
    }
}