/* 链表测试程序源文件Main.c, 和DoubleList.c一起编译 */

/* 包含头文件 */
#include "DoubleList.h"

/* 链表测试模块函数原型 */
void ShowList(List list);
void Insert(List list);
void Delete(List list);
void Locate(List list);
void Finde(List list);
void EatChar(void);

/* 主函数 */
int main(void)
{
    List list = InitList();
    ShowList(list);
    Insert(list);
    Delete(list);
    Locate(list);
    Finde(list);
    ClearList(list);
    ShowList(list);
    DestroyList(list);

    return 0;
}

/* 链表测试模块函数定义 */
void ShowList(List list)
{
    printf("当前链表:\n");
    printf("    >> 是否为空: ");
    printf("%s\n", ListEmpty(list) ? "是" : "否");
    printf("    >> 元素个数: ");
    printf("%d\n", ListLength(list));
    printf("    >> 元素内容: ");
    PrintList(list);
}

void Insert(List list)
{
    printf("开始插入元素...\n");
    printf("请输入待插入位序(按q退出): ");
    int i;
    int r;
    ElemType elem;
    while (scanf("%d", &i) == 1) {
        EatChar();
        ScanElem(&elem);
        EatChar();
        r = ListInsert(list, i, &elem);
        if (r == -1) {
            printf("申请内存失败!\n");
            break;
        } else if (r == 1) {
            printf("插入位序不合理, 请重新输入(按q退出): ");
        } else if (r == 0) {
            printf("插入成功!\n");
            printf("继续插入请输入插入位序, 否则请按q: ");
        }
    }
    EatChar();
    ShowList(list);
}

void Delete(List list)
{
    printf("开始删除元素...\n");
    printf("请输入待删除位序(退出请按q): ");
    int i;
    int r;
    ElemType elem;
    while (scanf("%d", &i) == 1) {
        EatChar();
        r = ListDelete(list, i, &elem);
        if (r == -1) {
            printf("链表为空!\n");
            break;
        } else if (r == 1) {
            printf("删除位序不合理, 请重新输入(按q退出): ");
        } else if (r == 0) {
            printf("删除成功! 被删除的元素是: (%d, %d)\n", elem.x, elem.y);
            printf("继续删除请输入删除位序, 否则请按q: ");
        }
    }
    EatChar();
    ShowList(list);
}

void Locate(List list)
{
    printf("开始定位元素...\n");
    ElemType elem;
    int i;
    printf("请输入待查找的元素(按\"x, y\"的格式): ");
    while (scanf("%d, %d", &elem.x, &elem.y) == 2) {
        EatChar();
        i = LocateElem(list, &elem);
        if (i == -1) {
            printf("链表为空!\n");
            break;
        } else if (i == 0) {
            printf("该元素不存在!\n");
            printf("请重新输入元素(按\"x, y\"的格式): ");
        } else {
            printf("元素(%d, %d)在链表中第%d个元素位置\n", elem.x, elem.y, i);
            printf("继续查找请输入待查找的元素(按\"x, y\"的格式): ");
        }
    }
    EatChar();
    ShowList(list);
}

void Finde(List list)
{
    printf("开始查找元素...\n");
    int i;
    ElemType elem;
    int r;
    printf("请输入要查找的位序(按q退出): ");
    while (scanf("%d", &i) == 1) {
        EatChar();
        r = GetElem(list, i, &elem);
        if (r == -1) {
            printf("链表为空!\n");
            break;
        } else if (r == 1) {
            printf("查找位置不合理, 请重新输入(按q退出): ");
        } else if (r == 0) {
            printf("位序为%d位置的元素为: (%d, %d)\n", i, elem.x, elem.y);
            printf("继续查找请输入位序(按q退出): ");
        }
    }
    EatChar();
    ShowList(list);
}

void EatChar(void)
{
    while (getchar() != '\n') {
        continue;
    }
}