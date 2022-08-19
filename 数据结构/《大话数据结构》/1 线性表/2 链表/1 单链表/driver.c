/* 单链表驱动程序driver.c, 和LinkList.c一起编译 */

/* 包含头文件 */
#include "LinkList.h"

/* 过程函数原型 */
void access(void);
void eatchars(void);
void shownow(LinkList *list);

void start(LinkList *list);
void insert(LinkList *list);
void delete(LinkList *list);
void change(LinkList *list);
void search(LinkList *list);
void reset(LinkList *list);

int main(void)
{
    printf("1. 创建链表\n");
    access();
    printf("开始创建...\n");
    LinkList list;
    LinkList *plist = &list;
    list.length = 0;
    list.start = NULL;
    printf("创建成功!\n");
    printf("操作结束!\n");
    start(plist);
    insert(plist);
    delete(plist);
    change(plist);
    search(plist);
    reset(plist);

    return 0;
}

/* 过程函数定义 */
void access(void)
{
    printf("请按任意键继续...");
    getchar();
}
void eatchars(void)
{
    while (getchar() != '\n');
}
void shownow(LinkList *list)
{
    printf(">> 现在的链表:\n");
    printf("    1) 是否为空: ");
    if (ListEmpty(list)) {
        printf("是\n");
    } else {
        printf("否\n");
    }
    printf("    2) 元素个数: %d\n", ListLength(list));
    printf("    3) 现在的元素: ");
    int r;
    r = ListTraverse(list);
    if (r == -1) {
        printf("链表未初始化\n");
    }
}

void start(LinkList *list)
{
    access();
    printf("2. 初始化链表\n");
    access();
    printf("请选择是否初始化链表:\n");
    printf("y) 是   n) 否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            printf("操作结束!\n");
            exit(EXIT_FAILURE);
        } else if (ch == 'y') {
            printf("开始初始化...\n");
            int r = InitList(list);
            if (r == -1) {
                printf("初始化失败!\n");
                exit(EXIT_FAILURE);
            } else if (r == 0) {
                printf("初始化成功!\n");
                break;
            }
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(list);
}
void insert(LinkList *list)
{
    access();
    printf("3. 插入元素\n");
    access();
    printf("请选择是否插入元素:\n");
    printf("y) 是   n) 否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("请输入要插入的位序(按q退出): ");
            int i;
            while (scanf("%d", &i) == 1) {
                eatchars();
                ElemType elem;
                GetElem(&elem);
                eatchars();
                printf("开始插入...\n");
                int r;
                r = ListInsert(list, i, &elem);
                if (r == -1) {
                    printf("插入失败! 链表未初始化!\n");
                    exit(EXIT_FAILURE);
                } else if (r == 1) {
                    printf("插入位序不合理, 请重新输入(按q退出): ");
                    continue;
                } else if (r == -2) {
                    printf("插入失败! 链表已满!\n");
                    break;
                } else if (r == 0) {
                    printf("插入成功!\n");
                    printf("继续插入请输入位序(退出请按q): ");
                    continue;
                }
            }
            eatchars();
            break;
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(list);
}
void delete(LinkList *list)
{
    access();
    printf("4. 删除元素\n");
    access();
    printf("请选择是否删除元素:\n");
    printf("y) 是   n) 否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("请输入您要删除的位序(按q退出): ");
            int i;
            while (scanf("%d", &i) == 1) {
                eatchars();
                ElemType elem;
                printf("开始删除...\n");
                int r = ListDelete(list, i, &elem);
                if (r == -1) {
                    printf("删除失败! 链表未初始化!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("删除失败! 链表为空!\n");
                    break;
                } else if (r == 1) {
                    printf("删除位序不合理, 请重新输入(按q退出): ");
                    continue;
                } else if (r == 0) {
                    printf("删除成功! 您删除的元素是: ");
                    ShowElem(&elem);
                    printf("\n");
                    printf("继续删除请输入您要删除的位序(退出请按q): ");
                }
            }
            eatchars();
            break;
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(list);
}
void change(LinkList *list)
{
    access();
    printf("5. 修改元素\n");
    access();
    printf("请选择是否修改元素:\n");
    printf("y) 是   n) 否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("请输入要修改的元素位序(按q退出): ");
            int i;
            while (scanf("%d", &i) == 1) {
                eatchars();
                ElemType data;
                GetElem(&data);
                eatchars();
                ElemType elem;
                printf("开始修改...\n");
                int r = ListChange(list, i, &data, &elem);
                if (r == -1) {
                    printf("修改失败! 链表未初始化!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("修改失败! 链表无元素!\n");
                    break;
                } else if (r == 1) {
                    printf("修改位序不合理, 请重新输入(按q退出): ");
                    continue;
                } else if (r == 0) {
                    printf("修改成功! 您修改的元素是: ");
                    ShowElem(&elem);
                    printf("\n");
                    printf("继续修改请输入待修改的位序(退出请按q): ");
                    continue;
                }
            }
            eatchars();
            break;
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(list);
}
void search(LinkList *list)
{
    access();
    printf("6. 查找元素\n");
    access();
    printf("请选择查找的方法:\n");
    printf("a) 按序查找     b) 按值查找     q) 退出\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'q') {
            break;
        } else if (ch == 'a') {
            printf("请输入您要查找的元素位序(按q退出): ");
            int i;
            while (scanf("%d", &i) == 1) {
                ElemType elem;
                printf("开始查找...\n");
                int r = ListSearch(list, i, &elem);
                if (r == -1) {
                    printf("查找失败! 链表未初始化!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("查找失败! 链表为空!\n");
                    break;
                } else if (r == 1) {
                    printf("查找位序不合理, 请重新输入(按q退出): ");
                    continue;
                } else if (r == 0) {
                    printf("查找成功! 您查找的元素是: ");
                    ShowElem(&elem);
                    printf("\n");
                    printf("继续查找请输入您要查找的元素位序(退出请按q): ");
                    continue;
                }
            }
            eatchars();
            break;
        } else if (ch == 'b') {
            printf("请输入您要查找的元素, 按照以下形式输入(输入q退出): (x, y)\n");
            ElemType elem;
            while (scanf("(%d, %d)", &elem.x, &elem.y) == 2) {
                eatchars();
                printf("开始查找...\n");
                int r = LocateElem(list, &elem);
                if (r == -1) {
                    printf("查找失败! 链表未初始化!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("查找失败! 链表无元素!\n");
                    break;
                } else {
                    printf("查找成功! ");
                    if (r == 0) {
                        printf("链表中无该元素!\n");
                    } else {
                        printf("元素 ");
                        ShowElem(&elem);
                        printf("在链表中的位序是: %d\n", r);
                    }
                    printf("继续查找请输入您要查找的元素, 按照以下形式输入(输入q退出): (x, y)\n");
                    continue;
                }
            }
            eatchars();
            break;
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(list);
}
void reset(LinkList *list)
{
    access();
    printf("7. 重置链表\n");
    access();
    printf("请选择重置链表的方式:\n");
    printf("a) 清空链表     b) 销毁链表     q) 退出\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'q') {
            printf("操作结束!\n");
            access();
            shownow(list);
            break;
        } else if (ch == 'a') {
            printf("开始清空链表...\n");
            int r = ClearList(list);
            if (r == -1) {
                printf("清空失败! 链表未初始化!\n");
                exit(EXIT_FAILURE);
            } else if (r == 0) {
                printf("清空成功!\n");
                printf("操作结束!\n");
                access();
                shownow(list);
                break;
            }
        } else if (ch == 'b') {
            goto c1;
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("程序结束!\n");
c1: printf("开始销毁数据...\n");
    int r = DestroyList(list);
    if (r == -1) {
        printf("销毁失败! 链表未初始化!\n");
    } else if (r == 0) {
        printf("销毁成功!\n");
    }
    access();
    shownow(list);
}