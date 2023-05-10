#include "Bunch.h"
#include <stdio.h>
#include <ctype.h>

void ShowBunch(const char *name, cPtrBunch bunch);
void Insert(PtrBunch bunch);

int main(void)
{
    PtrBunch bunch = CreateBunch();
    ShowBunch("bunch", bunch);
    Insert(bunch);
    ShowBunch("bunch", bunch);
    DestroyBunch(bunch);

    return 0;
}

void ShowBunch(const char *name, cPtrBunch bunch)
{
    printf(">> 当前链串(%s): \n", name);
    printf("    >> 是否为空: %s\n", BunchEmpty(bunch) ? "是" : "否");
    printf("    >> 元素个数: %d\n", Size(bunch));
    printf("    >> 背包内容:");
    for (constIterator beg = cBegin(bunch), end = cEnd(bunch); beg != end; beg = cNext(beg)) {
        printf(" ");
        PrintElem(StarConstIter(beg));
    }
    printf("\n");
}
void Insert(PtrBunch bunch)
{
    int ch;
    printf("请选择是否开始插入元素（Yes or Not) ：");
    if (tolower(ch = getchar()) == 'y') {
        while (getchar() != '\n');
        ElemType elem;
        while (ReadElem(&elem)) {
            Status s = Add(bunch, &elem);
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