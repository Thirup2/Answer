/* 一维数组驱动程序文件driver.c, 与Array.c一起编译 */
/* 包含头文件 */
#include "Array.h"

/* 过程函数原型 */
void access(void);
void eatchars(void);
void shownow(Array *array);

void start(Array *array);
void insert(Array *array);
void delete(Array *array);
void change(Array *array);
void search(Array *array);
void reset(Array *array);

int main(void)
{
    printf("1. 创建数组\n");
    access();
    printf("开始创建...\n");
    Array array;
    Array *parry = &array;
    printf("创建成功!\n");
    start(parry);
    insert(parry);
    delete(parry);
    change(parry);
    search(parry);
    reset(parry);

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
    while (getchar() != '\n') {
        continue;
    }
}
void shownow(Array *array)
{
    printf(">> 现在的数组:\n");
    printf("    1) 是否为空: ");
    if (ArrayEmpty(array)) {
        printf("否\n");
    } else {
        printf("是\n");
    }
    printf("    2) 元素个数: ");
    printf("%d\n", ArrayEmpty(array));
    printf("    3) 所有元素: ");
    ArrayTraverse(array);
}

void start(Array *array)
{
    access();
    printf("2. 初始化\n");
    access();
    printf("请选择是否进行初始化:\n");
    printf("y) 是   n) 否\n");
    int ch;
    bool r;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'y') {
            printf("开始初始化...\n");
            r = InitArray(array);
            if (r == true) {
                printf("初始化成功!\n");
                break;
            } else {
                printf("初始化失败! 数组指针出错!\n");
                exit(EXIT_FAILURE);
            }
        } else if (ch == 'n') {
            printf("操作结束!\n");
            exit(EXIT_FAILURE);
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(array);
}
void insert(Array *array)
{
    access();
    printf("3. 插入元素\n");
    access();
    ElemType elem;
    int i;
    int ch;
    int r;
    printf("请选择是否插入元素:\n");
    printf("y) 是   n) 否\n");
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("请输入要插入的位序(按q退出): ");
            while (scanf("%d", &i) == 1) {
                eatchars();
                printf("请输入要插入的值: ");
                scanf("%d", &elem);
                eatchars();
                printf("开始插入...\n");
                r = ArrayInsert(array, i, &elem);
                if (r == -1) {
                    printf("插入失败! 数组指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("插入失败! 插入值指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == 1) {
                    printf("插入失败! 数组已满!\n");
                    break;
                } else if (r == 2) {
                    printf("插入失败! 位序不合理, 请重新输入: ");
                    continue;
                } else if (r == 0) {
                    printf("插入成功!\n");
                    printf("继续插入请输入要插入的位序(否则请按q): ");
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
    shownow(array);
}
void delete(Array *array)
{
    access();
    printf("4. 删除元素\n");
    access();
    printf("请选择是否进行删除操作:\n");
    printf("y) 是   n) 否\n");
    int ch;
    int r;
    int i;
    ElemType elem;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("请输入您想要删除的位序(按q退出): ");
            while (scanf("%d", &i) == 1) {
                eatchars();
                printf("开始删除...\n");
                r = ArrayDelete(array, i, &elem);
                if (r == -1) {
                    printf("删除失败! 数组指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("删除失败! 接受值指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == 1) {
                    printf("删除失败! 位序不合理, 请重新输入: ");
                    continue;
                } else if (r == 0) {
                    printf("删除成功! ");
                    printf("您删除的元素是: %d\n", elem);
                    printf("继续删除请输入要删除的位序(否则请按q): ");
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
    shownow(array);
}
void change(Array *array)
{
    access();
    printf("5. 更改元素\n");
    access();
    int ch;
    int r;
    ElemType data, elem;
    int i;
    printf("请选择是否更改元素:\n");
    printf("y) 是   n) 否\n");
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("请输入要修改的位序(按q退出): ");
            while (scanf("%d", &i) == 1) {
                eatchars();
                printf("请输入要修改的值: ");
                scanf("%d", &elem);
                eatchars();
                printf("开始修改...\n");
                r = ArrayChange(array, i, &elem, &data);
                if (r == -1) {
                    printf("修改失败! 数组指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("修改失败! 位序不合理, 请重新输入: ");
                    continue;
                } else if (r == -3) {
                    printf("修改失败! 被修改值指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -4) {
                    printf("修改失败! 修改值指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == 0) {
                    printf("修改成功! ");
                    printf("被修改的值为: %d\n", data);
                    printf("继续修改请输入要修改的位序(否则请按q): ");
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
    shownow(array);
}
void search(Array *array)
{
    access();
    printf("6. 查找元素\n");
    access();
    printf("请选择查找方式:\n");
    printf("a) 按序查找  b) 按值查找  q) 退出\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'q') {
            break;
        } else if (ch == 'a') {
            int r;
            int i;
            ElemType elem;
            printf("请输入要查找的位序(按q退出): ");
            while (scanf("%d", &i) == 1) {
                eatchars();
                printf("开始查找...\n");
                r = ArraySearch(array, i, &elem);
                if (r == -1) {
                    printf("查找失败! 数组指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("查找失败! 被查找值指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -3) {
                    printf("查找失败! 位序不合理, 请重新输入: ");
                    continue;
                } else if (r == 0) {
                    printf("查找成功! 您查找的元素是: %d\n", elem);
                    printf("继续查找请输入要查找的位序(否则请按q): ");
                    continue;
                }
            }
            eatchars();
            break;
        } else if (ch == 'b') {
            ElemType elem;
            int r;
            printf("请输入要查找的元素值(按q退出): ");
            while (scanf("%d", &elem) == 1) {
                eatchars();
                printf("开始查找...\n");
                r = ArrayLocate(array, &elem);
                if (r == -1) {
                    printf("查找失败! 数组指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == -2) {
                    printf("查找失败! 查找值指针错误!\n");
                    exit(EXIT_FAILURE);
                } else if (r == 0) {
                    printf("查找成功! 数组中不存在该元素!\n");
                    printf("继续查找请输入要查找的元素值(否则请按q): ");
                    continue;
                } else {
                    printf("查找成功! 元素%d在数组中的位序是: %d\n", elem, r);
                    printf("继续查找请输入要查找的元素值(否则请按q): ");
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
    shownow(array);
}
void reset(Array *array)
{
    access();
    printf("7. 重置数组\n");
    access();
    printf("请选择是否重置数组:\n");
    printf("y) 是   n) 否\n");
    int ch;
    while ((ch = getchar()) != EOF) {
        eatchars();
        if (ch == 'n') {
            break;
        } else if (ch == 'y') {
            printf("开始重置...\n");
            bool r = ClearArray(array);
            if (r == false) {
                printf("重置失败! 数组指针错误!\n");
                exit(EXIT_FAILURE);
            } else {
                printf("重置成功!\n");
                break;
            }
        } else {
            printf("您的输入格式有误, 请重新输入: ");
            continue;
        }
    }
    printf("操作结束!\n");
    access();
    shownow(array);
}