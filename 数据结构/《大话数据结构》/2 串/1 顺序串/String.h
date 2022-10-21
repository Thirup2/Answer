/* 字符串接口头文件String.h */
#ifndef _STRING_H_
#define _STRING_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* 数据结构定义 */
typedef char ElemType;
struct string
{
    ElemType *string;               // 动态数组实现字符串
    int length;                 // 字符串长度(不含'\0')
};
typedef struct string String;   // 字符串类型
typedef String *PtrString;      // 字符串指针

/* 字符串接口函数原型 */

/*
** 操作: 打印一个字符
*/
void PrintChar(ElemType *ch);

/*
** 操作: 创建一个字符串, 使字符串只含下标为0的值, 不使用
** 参数: 一个字符串类型的值
*/
PtrString InitString(void);

/*
** 操作: 打印一个字符串
** 参数: 字符串类型的值
*/
void PrintString(PtrString S);

/*
** 操作: 用字符串常量初始化或赋值字符串
** 参数:
** 1. 待赋值字符串
** 2. 字符串常量
*/
void StrAssign(PtrString S, char *T);

/*
** 操作: 用字符串类型初始化或赋值字符串
** 参数:
** 1. 待赋值字符串
** 2. 字符串类型值
*/
void StrCopy(PtrString S, PtrString T);

/*
** 操作: 清空字符串
** 参数: 字符串类型值
*/
void ClearString(PtrString S);

/*
** 操作: 销毁字符串
** 参数: 字符串类型值
*/
void DestroyString(PtrString S);

/*
** 操作: 判断字符串是否是空串
** 参数: 字符串类型值
** 返回值:
** 1. 若字符串为空, 则返回true
** 2. 否则返回false
*/
bool StringEmpty(PtrString S);

/*
** 操作: 返回字符串的长度(不包括末尾NUL)
** 参数: 字符串类型值
** 返回值: 字符串的长度
*/
int StringLength(PtrString S);

/*
** 操作: 比较两个字符串的大小
** 参数: 用于比较的两个字符串
** 返回值:
** 1. 相等则返回0
** 2. 若第一个参数小, 则返回负数, 值为第一个不相等字符位序
** 3. 若第一个参数大, 则返回正数, 值为第一个不相等字符位序
*/
int StringCompare(PtrString S, PtrString T);

/*
** 操作: 联接两个字符串, 用一个字符串输出
** 参数:
** 1. 用于返回联接后的字符串
** 2. 用于联接的前部分内容
** 3. 用于联接的后部分内容
*/
void Concat(PtrString T, PtrString S1, PtrString S2);

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
int SubString(PtrString Sub, PtrString S, int pos, int len);

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
int Index(PtrString S, PtrString T, int pos);

/*
** 操作: 用KMP算法实现的Index
*/
int Index_KMP(PtrString S, PtrString T, int pos);

/*
** 操作: 用另一个字符串替换主串中出现的所有查找子串
** 参数:
** 1. 主串
** 2. 待替换子串(查找子串)
** 3. 用于替换的字符串
** 返回值: 被替换的子串个数
*/
int Replace(PtrString S, PtrString T, PtrString V);

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
int StrInsert(PtrString S, int pos, PtrString T);

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
int StrDelete(PtrString S, int pos, int len);

#endif