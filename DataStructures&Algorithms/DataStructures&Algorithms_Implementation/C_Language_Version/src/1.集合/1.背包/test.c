#include "Bag.h"
#include <stdio.h>
#include <ctype.h>

void ShowBag(const char *name, cPtrBag bag);
void Insert(PtrBag bag);

int main(void)
{
    PtrBag bag = CreateBag();
    ShowBag("bag", bag);
    Insert(bag);
    ShowBag("bag", bag);
    DestroyBag(bag);

    return 0;
}

void ShowBag(const char *name, cPtrBag bag)
{
    printf(">> 当前背包(%s)：\n", name);
    printf("    >> 是否为空: %s\n", BagEmpty(bag) ? "是" : "否");
    printf("    >> 元素个数: %d\n", Size(bag));
    printf("    >> 背包内容:");
    for (constIterator beg = cBegin(bag), end = cEnd(bag); beg != end; beg = cNext(beg)) {
        printf(" ");
        PrintElem(beg);
    }
    printf("\n");
}
void Insert(PtrBag bag)
{
    int ch;
    printf("请选择是否开始插入元素（Yes or Not）：");
    if (tolower(ch = getchar()) == 'y') {
        while (getchar() != '\n');
        ElemType elem;
        while (ReadElem(&elem)) {
            Status s = Add(bag, &elem);
            if (s == EXISTED) {
                printf("该元素已存在，请重新输入！\n");
                continue;
            } else if (s == SUCCESS) {
                printf("添加成功！\n");
            }
        }
    }
    while (getchar() != '\n');
    printf("插入进程已退出！\n");
}