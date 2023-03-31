#include "Bag.h"
#include <stdio.h>

void ShowBag(const char *name, PtrBag bag);

void EatChars(void);

int main(void)
{
    PtrBag BagInstance = InitBag();
    ShowBag("BagInstance", BagInstance);
    PtrCoord coord = InitCoord();
    while (ReadCoord(coord)) {
        Status sta;
        sta = InsertElem(BagInstance, coord);
        if (sta == ISIN) {
            printf("插入失败：元素已存在！\n");
        } else if (sta == ISFULL) {
            printf("插入失败：背包已满！\n");
        } else {
            printf("%s：插入成功！\n", CoordToString(coord));
        }
    }
    EatChars();
    ShowBag("BagInstance", BagInstance);
    size_t i;
    while (ReadCoord(coord)) {
        i = SearchData(BagInstance, coord);
        if (i == 0) {
            printf("元素不存在！\n");
        } else {
            printf("%s：%lu\n", CoordToString(coord), i);
        }
    }
    EatChars();
    DestroyCoord(coord);
    ShowBag("BagInstance", BagInstance);
    ClearBag(BagInstance);
    ShowBag("BagInstance", BagInstance);
    DestroyBag(BagInstance);

    return 0;
}

void ShowBag(const char *name, PtrBag bag)
{
    printf("%s:\n", name);
    printf("    >> 是否为空：%s\n", EmptyBag(bag) ? "是" : "否");
    printf("    >> 元素个数：%lu\n", BagSize(bag));
    printf("    >> 背包内容：");
    PtrCoord beg = Begin(bag);
    if (beg) {
        bool judge = false;
        PtrCoord end = End(bag);
        for (; beg != end; beg = Next(beg)) {
            if (judge) {
                printf(" ");
            }
            PrintCoord(beg);
            judge = true;
        }
        printf("\n");
    } else {
        printf("空\n");
    }
}

void EatChars(void)
{
    while (getchar() != '\n') {
    }
}