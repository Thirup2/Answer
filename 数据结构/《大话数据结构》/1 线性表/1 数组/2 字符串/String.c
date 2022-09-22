/* 字符串接口函数定义源文件String.c */

/* 包含头文件 */
#include "String.h"

/* 局部函数原型 */

/*
** 操作: 根据子串写入next数组, 用于Index_KMP函数中子串的回溯
** 参数:
** 1. 字符串
** 2. 数组指针
*/
void get_next(String S, int **next);

/*
** 操作: get_next函数的改进版
*/
void get_nextval(String S, int **nextval);

/* 动态分配实现字符串的API定义 */

/*
** 操作: 创建一个字符串
** 1. 将每一个元素都初始化为0
** 参数: 一个字符串类型的值
*/
void InitString(PTRS S)
{
    *S = (String) calloc(INITSIZE, sizeof(char));
    if (!(*S)) {
        exit(EXIT_FAILURE);
    }
}

/*
** 操作: 打印一个字符串
** 参数: 字符串类型的值
*/
void PrintString(String S)
{
    printf("%s\n", S);
}

/* 字符串接口函数定义 */

/*
** 操作: 用字符串常量初始化或赋值字符串
** 参数:
** 1. 待赋值字符串
** 2. 字符串常量
*/
void StrAssign(PTRS S, char *T)
{
    int len = StringLength(T);
    *S = (String) realloc(*S, (len + 1) * sizeof(char));
    if (!(*S)) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < len + 1; i++) {
        (*S)[i] = T[i];
    }
}

/*
** 操作: 用字符串类型初始化或赋值字符串
** 参数:
** 1. 待赋值字符串
** 2. 字符串类型值
*/
void StrCopy(PTRS S, String T)
{
    int len = StringLength(T);
    *S = (String) realloc(*S, (len + 1) * sizeof(char));
    if (!(*S)) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < len + 1; i++) {
        (*S)[i] = T[i];
    }
}

/*
** 操作: 清空字符串
** 参数: 字符串类型值
*/
void ClearString(String S)
{
    S[0] = '\0';
}

/*
** 操作: 销毁字符串
** 参数: 字符串类型值
*/
void DestroyString(String S)
{
    free(S);
}

/*
** 操作: 判断字符串是否是空串
** 参数: 字符串类型值
** 返回值:
** 1. 若字符串为空, 则返回true
** 2. 否则返回false
*/
bool StringEmpty(String S)
{
    if (S[0] == '\0') {
        return true;
    }
    return false;
}

/*
** 操作: 返回字符串的长度(不包括末尾NUL)
** 参数: 字符串类型值
** 返回值: 字符串的长度
*/
int StringLength(String S)
{
    int cnt = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        cnt++;
    }
    return cnt;
}

/*
** 操作: 比较两个字符串的大小
** 参数: 用于比较的两个字符串
** 返回值:
** 1. 相等则返回0
** 2. 若第一个参数小, 则返回负数, 值为第一个不相等字符位序
** 3. 若第一个参数大, 则返回正数, 值为第一个不相等字符位序
*/
int StringCompare(String S, String T)
{
    int len, lens, lent;
    lens = StringLength(S);
    lent = StringLength(T);
    int flag;
    if (lens == lent) {
        flag = 0;
        len = lens;
    } else if (lens < lent) {
        flag = -1;
        len = lens;
    } else {
        flag = 1;
        len = lent;
    }
    int i = 0;
    for (i = 0; i < len; i++) {
        if (S[i] > T[i]) {
            return i + 1;
        } else if (S[i] < T[i]) {
            return -(i + 1);
        }
    }
    return flag * (i + 1);
}

/*
** 操作: 联接两个字符串, 用一个字符串输出
** 参数:
** 1. 用于返回联接后的字符串
** 2. 用于联接的前部分内容
** 3. 用于联接的后部分内容
*/
void Concat(PTRS T, String S1, String S2)
{
    int lenS1, lenS2;
    lenS1 = StringLength(S1);
    lenS2 = StringLength(S2);
    *T = (String) realloc(*T, (lenS1 + lenS2 + 1) * sizeof(char));
    if (!(*T)) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < lenS1 + lenS2 + 1; i++) {
        for (int j = 0; j < lenS1; j++) {
            (*T)[i] = S1[j];
            i++;
        }
        for (int j = 0; j < lenS2 + 1; j++) {
            (*T)[i] = S2[j];
            i++;
        }
    }
}

/*
** 操作: 返回串中某个位置起某个长度的子串
** 参数:
** 1. 用于返回子串的字符串
** 2. 主串
** 3. 起始位置
** 4. 子串长度
** 返回值:
** 1. 若起始位置不合理返回1
** 2. 若子串长度不合理返回2
** 3. 否则执行操作返回0
*/
int SubString(PTRS Sub, String S, int pos, int len)
{
    int lens = StringLength(S);
    if (pos < 1 || pos > lens) {
        return 1;
    }
    if ((pos + len - 1) < 1 || (pos + len - 1) > lens) {
        return 2;
    }
    *Sub = (String) realloc(*Sub, (len + 1) * sizeof(char));
    int i = 0;
    while (i < len) {
        for (int j = pos - 1; j < pos + len - 1; j++) {
            (*Sub)[i] = S[j];
            i++;
        }
    }
    (*Sub)[i] = '\0';
    return 0;
}

/*
** 操作: 返回主串中某个子串从某个位置起第一次出现的位置
** 参数:
** 1. 主串
** 2. 待查找子串
** 3. 查找起始位置
** 返回值:
** 1. 若查找成功, 返回位置的值
** 2. 若未找到该子串, 则返回0
*/
int Index(String S, String T, int pos)
{
    if (pos<1 || pos>StringLength(S)) {
        return -1;
    }
    int i = pos - 1;
    int j = 0;
    while (S[i] != '\0' && T[j] != '\0') {
        if (S[i] == T[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (T[j] == 0) {
        return i - j + 1;
    } else {
        return 0;
    }
}

/*
** 操作: 用KMP算法实现的Index
*/
int Index_KMP(String S, String T, int pos)
{
    int *next = NULL;
    get_nextval(T, &next);
    int i = pos - 1;
    int j = 0;
    while (j == -1 || (S[i] != '\0' && T[j] != '\0')) {
        if (j == -1 || S[i] == T[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    free(next);
    if (T[j] == '\0') {
        return i - j + 1;
    } else {
        return 0;
    }
}

/*
** 操作: 用另一个字符串替换主串中出现的所有查找子串
** 参数:
** 1. 主串
** 2. 待替换子串(查找子串)
** 3. 用于替换的字符串
** 返回值: 被替换的子串个数
*/
int Replace(PTRS S, String T, String V)
{
    int n = 1;
    int lent = StringLength(T);
    int lenv = 0;
    int cnt = 0;
    while ((n = Index(*S, T, n + lenv - 1)) != 0) {
        if (lenv == 0) {
            lenv = StringLength(V);
        }
        StrDelete(S, n, lent);
        StrInsert(S, n, V);
        cnt++;
    }

    return cnt;
}

/*
** 操作: 在主串某个位置前插入字符串
** 参数:
** 1. 主串
** 2. 待插入位置
** 3. 用于插入的字符串
** 返回值:
** 1. 若插入位置不合理返回1
** 2. 否则执行操作返回0
*/
int StrInsert(PTRS S, int pos, String T)
{
    int lens, lent;
    lens = StringLength(*S);
    lent = StringLength(T);
    if (pos<1 || pos>lens + 1) {
        return 1;
    }
    String V = (String) calloc(lens + lent + 1, sizeof(char));
    if (!V) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < lens + lent + 1; i++) {
        for (int j = 0; j < lens + 1; j++) {
            if (j == pos - 1) {
                for (int q = 0; q < lent; q++) {
                    V[i++] = T[q];
                }
            }
            V[i++] = (*S)[j];
        }
    }
    *S = (String) realloc(*S, (lens + lent + 1) * sizeof(char));
    if (!(*S)) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < lens + lent + 1; i++) {
        (*S)[i] = V[i];
    }
    free(V);
    return 0;
}

/*
** 操作: 删除字符串某个位置起某个长度的子串内容
** 参数:
** 1. 主串
** 2. 起始位置
** 3. 待删除长度
** 返回值:
** 1. 若起始位置不合理返回1
** 2. 若删除长度不合理返回2
** 3. 否则执行操作返回0
*/
int StrDelete(PTRS S, int pos, int len)
{
    int lens;
    lens = StringLength(*S);
    if (pos<1 || pos>lens) {
        return 1;
    }
    if ((pos + len - 1) < 1 || (pos + len - 1) > lens) {
        return 2;
    }
    int length = lens - len;
    String V = (String) calloc(length + 1, sizeof(char));
    if (!V) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length + 1; i++) {
        for (int j = 0; j < lens + 1; j++) {
            if (j == pos - 1) {
                j += len;
            }
            V[i++] = (*S)[j];
        }
    }
    *S = (String) realloc(*S, (length + 1) * sizeof(char));
    if (!(*S)) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length + 1; i++) {
        (*S)[i] = V[i];
    }
    free(V);
    return 0;
}

/* 局部函数定义 */

/*
** 操作: 根据子串写入next数组, 用于Index_KMP函数中子串的回溯
** 参数:
** 1. 字符串
** 2. 数组指针
*/
void get_next(String S, int **next)
{
    int len = StringLength(S);
    *next = (int *) calloc(len, sizeof(int));
    if (!(*next)) {
        exit(EXIT_FAILURE);
    }
    (*next)[0] = -1;
    int i = 0;
    int k = -1;
    while (i < len - 1) {
        if (k == -1 || S[i] == S[k]) {
            ++k;
            ++i;
            (*next)[i] = k;
        } else {
            k = (*next)[k];
        }
    }
}

/*
** 操作: get_next函数的改进版
*/
void get_nextval(String S, int **nextval)
{
    int len = StringLength(S);
    *nextval = (int *) calloc(len, sizeof(int));
    if (!(*nextval)) {
        exit(EXIT_FAILURE);
    }
    (*nextval)[0] = -1;
    int i = 0;
    int k = -1;
    while (i < len - 1) {
        if (k == -1 || S[i] == S[k]) {
            ++i;
            ++k;
            if (S[i] != S[k]) {
                (*nextval)[i] = k;
            } else {
                (*nextval)[i] = (*nextval)[k];
            }
        } else {
            k = (*nextval)[k];
        }
    }
}