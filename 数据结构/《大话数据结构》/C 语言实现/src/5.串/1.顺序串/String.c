#define EXPORT
#define KMP
#ifdef KMP
#define IMPROVE
#endif

#include "String.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/* 局部函数声明 */

#ifdef KMP

/*
** 操作：填充next数组
** 参数：
** 1. 字符串
** 2. 下标数组
*/
static void DLL_CALL get_next(CSTRING string, size_char *next);

#endif

/* 接口实现 */

/*
** 操作：根据字符串常量生成字符串
** 参数：字符串常量
** 返回值：生成的字符串
*/
STRING DLL_CALL StrAssign(CPCHAR chars)
{
    size_t len = strlen(chars);
    if (len > MAXSIZE) {
        return NULL;
    }
    STRING string = (STRING) malloc((len + 2) * sizeof(CHAR));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    size_char i = 0;
    string[i++] = (size_char) len;
    while (i <= len) {
        string[i] = chars[i - 1];
        i++;
    }
    string[i] = '\0';
    return string;
}

/*
** 操作：根据字符串生成字符串
** 参数：字符串
** 返回值：新生成的字符串
*/
STRING DLL_CALL StrCopy(CSTRING string)
{
    size_t i = 0;
    STRING strcopy = (STRING) malloc((StrLength(string) + 2) * sizeof(CHAR));
    if (!strcopy) {
        exit(EXIT_FAILURE);
    }
    while (i < StrLength(string) + 2) {
        strcopy[i] = string[i];
        i++;
    }
    return strcopy;
}

/*
** 操作：清空字符串
** 参数：字符串
*/
void DLL_CALL ClearString(STRING string)
{
    string = (STRING) realloc(string, 2 * sizeof(CHAR));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    string[0] = 0;
    string[1] = '\0';
}

/*
** 操作：销毁字符串
** 参数：字符串
*/
void DLL_CALL DestroyString(STRING string)
{
    free(string);
}

/*
** 操作：判断字符串是否为空
** 参数：字符串
** 返回值：
** 1. 若字符串为空返回true
** 2. 否则返回false
*/
bool DLL_CALL StringEmpty(CSTRING string)
{
    if (StrLength(string) == 0) {
        return true;
    }
    return false;
}

/*
** 操作：返回字符串的长度
** 参数：字符串
** 返回值：字符串长度
*/
size_char DLL_CALL StrLength(CSTRING string)
{
    return string[0];
}

/*
** 操作：比较两个字符串
** 参数：两个待比较的字符串
** 返回值：
** 1. 若第一个字符串大于第二个字符串，则返回值大于0
** 2. 若第一个字符串等于第二个字符串，则返回值等于0
** 3. 若第一个字符串小于第二个字符串，则返回值小于0
*/
size_char DLL_CALL StrCompare(CSTRING str1, CSTRING str2)
{
    size_char len =
            (size_char) ((StrLength(str1) < StrLength(str2)) ?
                         StrLength(str1) :
                         StrLength(str2));
    size_char i = 1;
    while (i <= len + 1) {
        if (toupper(str1[i]) > toupper(str2[i])) {
            return i;
        } else if (toupper(str2[i]) > toupper(str1[i])) {
            return (size_char) -i;
        } else {
            if (str1[i] > str2[i]) {
                return i;
            } else if (str1[i] < str2[i]) {
                return (size_char) -i;
            } else {
                i++;
            }
        }
    }
    if (StrLength(str1) == StrLength(str2)) {
        return 0;
    } else {
        return 0;
    }
}

/*
** 操作：连接两个字符串
** 参数：
** 1. 结果字符串的前段
** 2. 结果字符串的后段
** 返回值：连接后的字符串
*/
STRING DLL_CALL Concat(CSTRING str1, CSTRING str2)
{
    size_t len = StrLength(str1) + StrLength(str2);
    if (len > MAXSIZE) {
        return NULL;
    }
    STRING string = (STRING) malloc((len + 2) * sizeof(CHAR));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    string[0] = (size_char) len;
    size_char i = 1;
    size_char j = 1;
    while (j <= StrLength(str1)) {
        string[i++] = str1[j++];
    }
    j = 1;
    while (j <= StrLength(str2)) {
        string[i++] = str2[j++];
    }
    string[i] = '\0';
    return string;
}

/*
** 操作：返回子串
** 参数：
** 1. 主串
** 2. 起始位置
** 3. 子串长度
** 返回值：
** 1. 若长度或位置不合理返回NULL
** 2. 否则返回该子串
*/
STRING DLL_CALL SubString(CSTRING string, size_char pos, size_char len)
{
    if (pos < 1 || pos + len - 1 > StrLength(string)) {
        return NULL;
    }
    STRING substring = (STRING) malloc((len + 2) * sizeof(CHAR));
    if (!substring) {
        exit(EXIT_FAILURE);
    }
    substring[0] = len;
    size_char i = 0;
    while (i < len) {
        substring[i + 1] = string[pos + i];
        i++;
    }
    substring[i + 1] = '\0';
    return substring;
}

/*
** 操作：匹配字符串
** 参数：
** 1. 主串
** 2. 待匹配子串
** 3. 起始匹配位置
** 返回值：
** 1. 若待匹配子串为空串，返回-1
** 2. 若无匹配子串，返回-2
** 3. 否则返回匹配的位置
*/
#ifndef KMP
// 朴素的模式匹配算法
size_char DLL_CALL Index(CSTRING string, CSTRING substring, size_char pos)
{
    if (StringEmpty(substring)) {
        return -1;
    }
    size_char i = pos;
    size_char j = 1;
    while (i <= string[0] && j <= substring[0]) {
        if (string[i] == substring[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > substring[0]) {
        return i - substring[0];
    } else {
        return -2;
    }
}
#else

// KMP模式匹配算法
size_char DLL_CALL Index(CSTRING string, CSTRING substring, size_char pos)
{
    if (StringEmpty(substring)) {
        return -1;
    }
    size_char i = pos;
    size_char j = 1;
    size_char next[MAXSIZE];
    get_next(substring, next);
    while (i <= string[0] && j <= substring[0]) {
        if (j == 0 || string[i] == substring[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j > substring[0]) {
        return (size_char) (i - substring[0]);
    } else {
        return -2;
    }
}

#endif

/*
** 操作：替换子串
** 参数：
** 1. 主串
** 2. 待替换子串
** 3. 用于替换的子串
** 返回值：
** 1. 若待替换子串为空串返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status DLL_CALL Replace(STRING string, CSTRING substring, CSTRING restring)
{
    if (StringEmpty(substring)) {
        return ISEMPTY;
    }
    size_char len = StrLength(substring);
    size_char now = Index(string, substring, 1);
    while (now > 0) {
        StrDelete(string, now, len);
        StrInsert(string, now, restring);
        now = (size_char) (now + StrLength(restring));
        now = Index(string, substring, now);
    }
    return SUCCESS;
}

/*
** 操作：插入字符串
** 参数：
** 1. 主串
** 2. 插入位置
** 3. 插入的字符串
** 返回值：
** 1. 若插入位置不合理返回WRONGPOS
** 2. 若长度超过最大长度返回ISFULL
** 3. 否则执行操作返回SUCCESS
*/
Status DLL_CALL StrInsert(STRING string, size_char pos, CSTRING substring)
{
    if (pos < 1 || pos > StrLength(string) + 1) {
        return WRONGPOS;
    }
    size_t sub_len = (ssize_t) StrLength(substring);
    size_t len = StrLength(string) + StrLength(substring);
    if (len > MAXSIZE) {
        return ISFULL;
    }
    string[0] = (size_char) len;
    string = (STRING) realloc(string, (len + 2) * sizeof(CHAR));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    for (size_char i = (size_char) (len + 1), j = (size_char) (i - sub_len); j >= pos; i--, j--) {
        string[i] = string[j];
    }
    for (size_char i = pos, j = 1; (size_t) j <= sub_len; i++, j++) {
        string[i] = substring[j];
    }
    return SUCCESS;
}

/*
** 操作：删除字符串
** 参数：
** 1. 主串
** 2. 删除起始位置
** 3. 删除字符串长度
** 返回值：
** 1. 若字符串为空返回ISEMPTY
** 2. 若删除长度或位置错误返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status DLL_CALL StrDelete(STRING string, size_char pos, size_char len)
{
    size_char str_len = StrLength(string);
    size_char i = 0;
    while (pos + len + i <= str_len + 1) {
        string[pos + i] = string[pos + len + i];
        i++;
    }
    string = (STRING) realloc(string, (str_len - len + 2) * sizeof(CHAR));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    string[0] = (size_char) (str_len - len);
    return SUCCESS;
}

/*
** 操作：打印字符串
** 参数：字符串
*/
void DLL_CALL PrintString(CSTRING string)
{
    size_char i = 1;
    while (i <= StrLength(string)) {
        printf("%c", string[i++]);
    }
}

/* 局部函数定义 */

/*
** 操作：填充next数组
** 参数：
** 1. 字符串
** 2. 下标数组
*/
#ifdef KMP
#ifndef IMPROVE
// 一般KMP模式匹配
static void DLL_CALL get_next(CSTRING string, size_char *next)
{
    size_char i, k;
    i = 1;
    k = 0;
    next[1] = 0;
    while (i < string[0]) {
        if (k == 0 || string[i] == string[k]) {
            ++i;
            ++k;
            next[i] = k;
        } else {
            k = next[k];
        }
    }
}
#else

// 改进的KMP模式匹配
static void DLL_CALL get_next(CSTRING string, size_char *next)
{
    size_char i, k;
    i = 1;
    k = 0;
    next[1] = 0;
    while (i < string[0]) {
        if (k == 0 || string[i] == string[k]) {
            ++i;
            ++k;
            if (string[i] != string[k]) {
                next[i] = k;
            } else {
                next[i] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}

#endif
#endif