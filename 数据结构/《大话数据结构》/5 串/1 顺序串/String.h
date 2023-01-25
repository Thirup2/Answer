/* 顺序串接口头文件 */
#ifndef _STRING_H_
#define _STRING_H_

/* 包含头文件 */
#include "../../0 Head/Status.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/* 顺序串类型定义 */
typedef char CHAR;
typedef char *PCHAR;
typedef const char *CPCHAR;

struct string
{
    size_t length;
    PCHAR string;               // 第一个元素不保存内容
};
typedef struct string STRING;
typedef STRING *PSTRING;
typedef const STRING *CPSTRING;

/* 顺序串函数接口 */

/*
** 操作：根据字符串常量生成字符串
** 参数：字符串常量
** 返回值：生成的字符串
*/
PSTRING StrAssign(CPCHAR chars);

/*
** 操作：根据字符串生成字符串
** 参数：字符串
** 返回值：新生成的字符串
*/
PSTRING StrCopy(CPSTRING string);

/*
** 操作：清空字符串
** 参数：字符串
*/
void ClearString(PSTRING string);

/*
** 操作：销毁字符串
** 参数：字符串
*/
void DestroyString(PSTRING string);

/*
** 操作：判断字符串是否为空
** 参数：字符串
** 返回值：
** 1. 若字符串为空返回true
** 2. 否则返回false
*/
bool StringEmpty(CPSTRING string);

/*
** 操作：返回字符串的长度
** 参数：字符串
** 返回值：字符串长度
*/
size_t StrLength(CPSTRING string);

/*
** 操作：比较两个字符串
** 参数：两个待比较的字符串
** 返回值：
** 1. 若第一个字符串大于第二个字符串，则返回值大于0
** 2. 若第一个字符串等于第二个字符串，则返回值等于0
** 3. 若第一个字符串小于第二个字符串，则返回值小于0
*/
int StrCompare(CPSTRING str1, CPSTRING str2);

/*
** 操作：连接两个字符串
** 参数：
** 1. 结果字符串的前段
** 2. 结果字符串的后段
** 返回值：连接后的字符串
*/
PSTRING Concat(CPSTRING str1, CPSTRING str2);

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
PSTRING SubString(CPSTRING string, size_t pos, size_t len);

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
long long int Index(CPSTRING string, CPSTRING substring, size_t pos);

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
Status Replace(PSTRING string, CPSTRING substring, CPSTRING restring);

/*
** 操作：插入字符串
** 参数：
** 1. 主串
** 2. 插入位置
** 3. 插入的字符串
** 返回值：
** 1. 若插入位置不合理返回WRONGPOS
** 2. 否则执行操作返回SUCCESS
*/
Status StrInsert(PSTRING string, size_t pos, CPSTRING substring);

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
Status StrDelete(PSTRING string, size_t pos, size_t len);

/*
** 操作：打印字符串
** 参数：字符串
*/
void PrintString(CPSTRING string);

/* 接口实现 */

/*
** 操作：根据字符串常量生成字符串
** 参数：字符串常量
** 返回值：生成的字符串
*/
PSTRING StrAssign(CPCHAR chars)
{
    size_t len = strlen(chars);
    PSTRING string = (PSTRING) malloc(sizeof(STRING));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    string->length = len;
    string->string = (PCHAR) malloc((len + 2) * sizeof(CHAR));
    if (!string->string) {
        exit(EXIT_FAILURE);
    }
    size_t i = 1;
    while (i <= len) {
        string->string[i] = chars[i - 1];
    }
    string->string[i] = '\0';
    return string;
}

/*
** 操作：根据字符串生成字符串
** 参数：字符串
** 返回值：新生成的字符串
*/
PSTRING StrCopy(CPSTRING string)
{
    PSTRING strcopy = (PSTRING) malloc(sizeof(STRING));
    if (!strcopy) {
        exit(EXIT_FAILURE);
    }
    strcopy->length = string->length;
    strcopy->string = (PCHAR) malloc((string->length + 2) * sizeof(CHAR));
    if (!strcopy->string) {
        exit(EXIT_FAILURE);
    }
    size_t i = 0;
    while (i < string->length + 2) {
        strcopy->string[i] = string->string[i];
    }
    return strcopy;
}

/*
** 操作：清空字符串
** 参数：字符串
*/
void ClearString(PSTRING string)
{
    string->length = 0;
    string->string = (PCHAR) realloc(string->string, 2 * sizeof(CHAR));
    if (!string->string) {
        exit(EXIT_FAILURE);
    }
    string->string[1] = '\0';
}

/*
** 操作：销毁字符串
** 参数：字符串
*/
void DestroyString(PSTRING string)
{
    free(string->string);
    free(string);
}

/*
** 操作：判断字符串是否为空
** 参数：字符串
** 返回值：
** 1. 若字符串为空返回true
** 2. 否则返回false
*/
bool StringEmpty(CPSTRING string)
{
    if (string->length == 0) {
        return true;
    }
    return false;
}

/*
** 操作：返回字符串的长度
** 参数：字符串
** 返回值：字符串长度
*/
size_t StrLength(CPSTRING string)
{
    return string->length;
}

/*
** 操作：比较两个字符串
** 参数：两个待比较的字符串
** 返回值：
** 1. 若第一个字符串大于第二个字符串，则返回值大于0
** 2. 若第一个字符串等于第二个字符串，则返回值等于0
** 3. 若第一个字符串小于第二个字符串，则返回值小于0
*/
int StrCompare(CPSTRING str1, CPSTRING str2)
{
    size_t i = 1;
    size_t len = (StrLength(str1) > StrLength(str2)) ? StrLength(str2) : StrLength(str1);
    while (i <= len + 1) {
        if (toupper(str1->string[i]) > toupper(str2->string[i])) {
            return i;
        } else if (toupper(str1->string[i]) < toupper(str2->string[i])) {
            return -i;
        } else {
            if (str1->string[i] > str2->string[i]) {
                return i;
            } else if (str1->string[i] < str2->string[i]) {
                return -i;
            } else {
                i++;
            }
        }
    }
    if (StrLength(str1) == StrLength(str2)) {
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
PSTRING Concat(CPSTRING str1, CPSTRING str2)
{
    size_t len = str1->length + str2->length;
    PSTRING string = (PSTRING) malloc(sizeof(STRING));
    if (!string) {
        exit(EXIT_FAILURE);
    }
    string->length = len;
    string->string = (PCHAR) malloc((len + 2) * sizeof(CHAR));
    if (!string->string) {
        exit(EXIT_FAILURE);
    }
    size_t i = 1;
    size_t j = 1;
    while (j <= str1->length) {
        string->string[i++] = str1->string[j++];
    }
    j = 1;
    while (j <= str2->length) {
        string->string[i++] = str2->string[j++];
    }
    string->string[i] = '\0';
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
PSTRING SubString(CPSTRING string, size_t pos, size_t len)
{
    if (pos < 1 || pos + len - 1 > string->length) {
        return NULL;
    }
    PSTRING str = (PSTRING) malloc(sizeof(STRING));
    if (!str) {
        exit(EXIT_FAILURE);
    }
    str->length = len;
    str->string = (PCHAR) malloc((len + 2) * sizeof(CHAR));
    if (!str->string) {
        exit(EXIT_FAILURE);
    }
    size_t i = 0;
    while (i < len) {
        str->string[i + 1] = string->string[pos + i];
        i++;
    }
    str->string[i + 1] = '\0';
    return str;
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
long long int Index(CPSTRING string, CPSTRING substring, size_t pos);

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
Status Replace(PSTRING string, CPSTRING substring, CPSTRING restring);

/*
** 操作：插入字符串
** 参数：
** 1. 主串
** 2. 插入位置
** 3. 插入的字符串
** 返回值：
** 1. 若插入位置不合理返回WRONGPOS
** 2. 否则执行操作返回SUCCESS
*/
Status StrInsert(PSTRING string, size_t pos, CPSTRING substring);

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
Status StrDelete(PSTRING string, size_t pos, size_t len);

/*
** 操作：打印字符串
** 参数：字符串
*/
void PrintString(CPSTRING string);

#endif