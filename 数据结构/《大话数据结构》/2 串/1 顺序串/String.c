/* 字符串接口函数文件String.c */

/* 包含头文件 */
#include "String.h"

/* 局部函数原型 */

/*
** 操作: 计算next数组
*/
void get_next(PtrString T, int *next);

/*
** 操作: 优化后的get_next操作
*/
void get_nextval(PtrString T, int *nextval);

/* 字符串接口函数定义 */

/*
** 操作: 打印一个字符
*/
void PrintChar(ElemType *ch)
{
    printf("%c", *ch);
}

/*
** 操作: 创建一个字符串, 使字符串只含下标为0的值, 不使用
** 参数: 一个字符串类型的值
*/
PtrString InitString(void)
{
    PtrString string = (PtrString) malloc(sizeof(String));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    string->string = (ElemType *) malloc(sizeof(ElemType));
    if (!string->string) {
        exit(EXIT_FAILURE);
    }
    string->length = 0;
    return string;
}

/*
** 操作: 打印一个字符串
** 参数: 字符串类型的值
*/
void PrintString(PtrString S)
{
    if (!StringEmpty(S)) {
        for (int i = 1; i <= StringLength(S); i++) {
            PrintChar(&(S->string[i]));
        }
    }
}

/*
** 操作: 用字符串常量初始化或赋值字符串
** 参数:
** 1. 待赋值字符串
** 2. 字符串常量
*/
void StrAssign(PtrString S, char *T)
{
    int len = strlen(T);
    S->string = (ElemType *) realloc(S->string, (len + 2) * sizeof(ElemType));
    if (!S->string) {
        exit(EXIT_FAILURE);
    }
    S->length = len;
    for (int i = 0; i <= StringLength(S); i++) {
        S->string[i + 1] = T[i];
    }
}

/*
** 操作: 用字符串类型初始化或赋值字符串
** 参数:
** 1. 待赋值字符串
** 2. 字符串类型值
*/
void StrCopy(PtrString S, PtrString T)
{
    S->string = (ElemType *) realloc(S->string, (T->length + 2) * sizeof(ElemType));
    if (!S->string) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= T->length; i++) {
        S->string[i + 1] = T->string[i + 1];
    }
    S->length = T->length;
}

/*
** 操作: 清空字符串
** 参数: 字符串类型值
*/
void ClearString(PtrString S)
{
    S->string = (ElemType *) realloc(S->string, sizeof(ElemType));
    if (!S->string) {
        exit(EXIT_FAILURE);
    }
    S->length = 0;
}

/*
** 操作: 销毁字符串
** 参数: 字符串类型值
*/
void DestroyString(PtrString S)
{
    free(S->string);
    free(S);
}

/*
** 操作: 判断字符串是否是空串
** 参数: 字符串类型值
** 返回值:
** 1. 若字符串为空, 则返回true
** 2. 否则返回false
*/
bool StringEmpty(PtrString S)
{
    if (StringLength(S) == 0) {
        return true;
    }
    return false;
}

/*
** 操作: 返回字符串的长度(不包括末尾NUL)
** 参数: 字符串类型值
** 返回值: 字符串的长度
*/
int StringLength(PtrString S)
{
    return S->length;
}

/*
** 操作: 比较两个字符串的大小
** 参数: 用于比较的两个字符串
** 返回值:
** 1. 相等则返回0
** 2. 若第一个参数小, 则返回负数, 值为第一个不相等字符位序
** 3. 若第一个参数大, 则返回正数, 值为第一个不相等字符位序
*/
int StringCompare(PtrString S, PtrString T)
{
    int len = StringLength(S) > StringLength(T) ? StringLength(T) : StringLength(S);
    for (int i = 0; i < len; i++) {
        if (S->string[i + 1] < T->string[i + 1]) {
            return -(i + 1);
        } else if (S->string[i + 1] > T->string[i + 1]) {
            return i + 1;
        }
    }
    return 0;
}

/*
** 操作: 联接两个字符串, 用一个字符串输出
** 参数:
** 1. 用于返回联接后的字符串
** 2. 用于联接的前部分内容
** 3. 用于联接的后部分内容
*/
void Concat(PtrString T, PtrString S1, PtrString S2)
{
    int len = StringLength(S1) + StringLength(S2);
    T->string = (ElemType *) realloc(T->string, (len + 2) * sizeof(ElemType));
    if (!T->string) {
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i <= StringLength(S1); i++) {
        T->string[i] = S1->string[i];
    }
    for (int i = StringLength(S1) + 1, j = 1; j <= StringLength(S2) + 1; j++, i++) {
        T->string[i] = S2->string[j];
    }
    T->length = len;
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
int SubString(PtrString Sub, PtrString S, int pos, int len)
{
    if (pos<1 || pos>StringLength(S)) {
        return 1;
    }
    if ((pos + len) < 1 || (pos + len) > StringLength(S)) {
        return 2;
    }
    Sub->string = (ElemType *) realloc(Sub->string, (len + 2) * sizeof(ElemType));
    if (!Sub->string) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0, j = pos; i < len; i++, j++) {
        Sub->string[i + 1] = S->string[j];
    }
    Sub->string[len + 1] = '\0';
    Sub->length = len;
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
int Index(PtrString S, PtrString T, int pos)
{
    int i = pos;
    int j = 1;
    while (i <= StringLength(S) && j <= StringLength(T)) {
        if (S->string[i] == T->string[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > StringLength(T)) {
        return i - StringLength(T);
    } else {
        return 0;
    }
}

/*
** 操作: 用KMP算法实现的Index
*/
int Index_KMP(PtrString S, PtrString T, int pos)
{
    int i = pos;
    int j = 1;
    int *next = (int *) malloc((StringLength(T) + 1) * sizeof(int));
    get_nextval(T, next);
    while (i <= StringLength(S) && j <= StringLength(T)) {
        if (j == 0 || S->string[i] == T->string[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    free(next);
    if (j > StringLength(T)) {
        return i - StringLength(T);
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
int Replace(PtrString S, PtrString T, PtrString V)
{
    int len_s = StringLength(S);
    int len_t = StringLength(T);
    int len_v = StringLength(V);
    int pos_ind;
    int pos_rep = 1;
    int cnt = 0;
    while (pos_ind = Index_KMP(S, T, pos_rep)) {
        StrDelete(S, pos_ind, len_t);
        StrInsert(S, pos_ind, V);
        pos_rep = pos_ind + len_v;
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
int StrInsert(PtrString S, int pos, PtrString T)
{
    if (pos<1 || pos>StringLength(S) + 1) {
        return 1;
    }
    int len_s = StringLength(S);
    int len_t = StringLength(T);
    S->string = (ElemType *) realloc(S->string, (len_s + len_t + 2) * sizeof(ElemType));
    if (!S->string) {
        exit(EXIT_FAILURE);
    }
    for (int i = len_s + len_t + 1; i >= pos + len_t; i--) {
        S->string[i] = S->string[i - len_t];
    }
    for (int i = pos, j = 0; j < len_t; j++, i++) {
        S->string[i] = T->string[j + 1];
    }
    S->length = len_s + len_t;
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
int StrDelete(PtrString S, int pos, int len)
{
    if (pos<1 || pos>StringLength(S)) {
        return 1;
    }
    if ((pos + len) < 1 || (pos + len) > StringLength(S)) {
        return 2;
    }
    for (int i = pos, j = pos + len; j <= S->length + 1; j++, i++) {
        S->string[i] = S->string[j];
    }
    S->string = (ElemType *) realloc(S->string, (StringLength(S) - len + 2) * sizeof(ElemType));
    if (!S->string) {
        exit(EXIT_FAILURE);
    }
    S->length = StringLength(S) - len;
    return 0;
}

/* 局部函数定义 */

/*
** 操作: 计算next数组
*/
void get_next(PtrString T, int *next)
{
    int i = 1, k = 0;
    next[1] = 0;
    while (i < StringLength(T)) {
        if (k == 0 || T->string[i] == T->string[k]) {
            ++i;
            ++k;
            next[i] = k;
        } else {
            k = next[k];
        }
    }
}

/*
** 操作: 优化后的get_next操作
*/
void get_nextval(PtrString T, int *nextval)
{
    int i = 1, k = 0;
    nextval[1] = 0;
    while (i < StringLength(T)) {
        if (k == 0 || T->string[i] == T->string[k]) {
            ++i;
            ++k;
            if (T->string[i] != T->string[k]) {
                nextval[i] = k;
            } else {
                nextval[i] = nextval[k];
            }
        } else {
            k = nextval[k];
        }
    }
}