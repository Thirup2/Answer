/* 串函数接口文件String.c */
#include "String.h"
#include <stdlib.h>

/* 局部函数原型 */
// 操作: 获取Index函数需要的next值
void get_nextval(String T, int *nextval);

/* 接口函数定义 */
// 操作: 生成一个其值等于字符串常量chars的串T
bool StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE) {
        return false;
    } else {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; ++i) {
            T[i] = *(chars + i - 1);
        }
        return true;
    }
}

// 操作: 由串复制得串T
bool StrCopy(String T, String S)
{
    for (int i = 0; i <= S[0]; ++i) {
        T[i] = S[i];
    }
    return true;
}

// 操作: 将串清空
void ClearString(String S)
{
    S[0] = 0;
}

// 操作: 判断串S是否为空
bool StringEmpty(String S)
{
    if (S[0] == 0) {
        return true;
    } else {
        return false;
    }
}

// 操作: 返回串的元素个数, 即串的长度
int StrLength(String S)
{
    return S[0];
}

// 操作: 比较两个串, 若S>T, 返回值>0; 若S=T, 返回0; 若S<T, 返回值<0
int StrCompare(String S, String T)
{
    int n;
    n = S[0] > T[0] ? T[0] : S[0];
    for (int i = 1; i <= n; ++i) {
        if (S[i] != T[i]) {
            return S[i] - T[i];
        }
    }
    if (n == S[0]) {
        return T[n + 1] - '\0';
    } else if (n == T[0]) {
        return S[n + 1] - '\0';
    } else {
        return 0;
    }
}

// 操作: 用T返回串S1和S2联接而成的新串
bool Concat(String T, String S1, String S2)
{
    if (strlen(S1) + strlen(S2) > MAXSIZE + 2) {
        return false;
    }
    T[0] = strlen(S1) + strlen(S2) - 2;
    for (int i = 1; i <= strlen(S1) - 1; ++i) {
        T[i] = S1[i];
    }
    for (int i = strlen(S1), j = 1; i < T[0]; ++i, ++j) {
        T[i] = S2[j];
    }
    return true;
}

// 操作: 用Sub返回串S的第pos个字符起长度为len的子串
int SubString(String Sub, String S, int pos, int len)
{
    if (pos<1 || pos>StrLength(S)) {
        return -2;      // pos位置错误
    }
    if (len < 0 || len + pos>StrLength(S) + 1) {
        return -1;      // len位置错误
    }
    Sub[0] = len;
    for (int i = 1, j = pos; i <= len; ++i) {
        Sub[i] = S[j];
    }
    return 0;
}

// 操作: 若主串S中存在和串T相同的子串, 则返回它在主串S中第pos个字符后第一次出现的位置, 否则返回0
int Index(String S, String T, int pos)
{
    int i = pos;
    int j = 1;
    int next[255];
    get_nextval(T, next);
    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > T[0]) {
        return i - T[0];
    } else {
        return 0;
    }
}

// 操作: 用V替换主串中出现的所有与T相等的不重叠的子串
int Replace(String S, String T, String V)
{
    if (T[0] > S[0]) {
        return -2;      // T长度错误
    }
    if (V[0] > S[0]) {
        return -1;      // V长度错误
    }
    int j;
    int n = V[0] - T[0];
    for (int i = 1;
         i < MAXSIZE + 1 && (j = Index(S, T, i)) != 0;
         i += j + T[0]) {
        S[0] += n;
        if (S[0] > MAXSIZE) {
            return -3;      // S溢出
        }
        for (int m = S[0] + n; m > j; --m) {
            S[m] = S[m - 1];
        }
        for (int m = j, q = 1; m < j + V[0]; ++m) {
            S[m] = V[q];
        }
    }
    return 0;
}

// 操作: 在串的第pos个字符之前插入串T
bool StrInsert(String S, int pos, String T)
{
    if (S[0] + T[0] > MAXSIZE) {
        return false;
    }
    for (int i = pos; i < pos + T[0]; ++i) {
        S[i + T[0]] = S[i];
    }
    for (int i = pos, j = 1; i < pos + T[0]; ++i) {
        S[i] = T[j];
    }
    S[0] += T[0];
    return true;
}

// 操作: 从串S中删除第pos个字符起长度为len的子串
bool StrDelete(String S, int pos, int len)
{
    if (pos + len > S[0]) {
        return false;
    }
    for (int i = pos; i < pos + len; ++i) {
        S[i] = S[i + len];
    }
    S[0] -= len;
    return true;
}

/* 局部函数定义 */
void get_nextval(String T, int *nextval)
{
    int i, k;
    i = 1;
    k = 0;
    nextval[1] = 0;
    while (i < T[0]) {                      // 此处T[0]表示串T的长度
        if (k == 0 || T[i] == T[k]) {       // T[i]表示后缀的单个字符, T[k]表示前缀的单个字符
            ++i;
            ++k;
            if (T[i] != T[k]) {             // 若当前字符与前缀字符不同
                nextval[i] = k;             // 则当前的k为nextval在i位置的值
            } else {
                nextval[i] = nextval[k];    // 如果与前缀字符相同, 则将前缀字符的
            }                               // nextval值赋值给nextval在i位置的值
        } else {
            k = nextval[k];                 // 若字符不相同, 则k值回溯
        }
    }
}