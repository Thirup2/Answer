/* 串接口函数头文件String.h */
#ifndef _STRING_H_
#define _STRING_H_

#include <stdbool.h>

/* 数据结构定义 */
#define MAXSIZE 40
typedef char ElemType;
typedef ElemType String[MAXSIZE + 1];       // 0号单元存放串的长度

/* 接口函数原型 */

// 操作: 生成一个其值等于字符串常量chars的串T
// 前提条件: chars的长度不得大于最大长度
// 后置条件: 若失败返回false, 成功返回true
bool StrAssign(String T, char *chars);

// 操作: 由串复制得串T
// 前提条件: 串S存在, 且为String类型
// 后置条件: 成功则返回true, 否则返回false
bool StrCopy(String T, String S);

// 操作: 将串清空
// 前提条件: 串S存在
// 后置条件: 将S[0]置为0
void ClearString(String S);

// 操作: 判断串S是否为空
// 后置条件: 若为空则返回true, 否则返回false
bool StringEmpty(String S);

// 操作: 返回串的元素个数, 即串的长度
// 前提条件: 串S存在
int StrLength(String S);

// 操作: 比较两个串, 若S>T, 返回值>0; 若S=T, 返回0; 若S<T, 返回值<0
// 前提条件: 串S和串T都为String类型
int StrCompare(String S, String T);

// 操作: 用T返回串S1和S2联接而成的新串
// 前提条件: 串T, S1, S2都为String类型
bool Concat(String T, String S1, String S2);

// 操作: 用Sub返回串S的第pos个字符起长度为len的子串
// 前提条件: 串S存在, 1<=pos<=StrLength(S), 且0<=len<=StrLength(S)-pos+1
int SubString(String Sub, String S, int pos, int len);

// 操作: 若主串S中存在和串T相同的的子串, 则返回它在主串S中第pos个字符后第一次出现的位置, 否则返回0
// 前提条件: 串S和T存在, T是非空串, 1<=pos<=StrLength(S)
// 后置条件: 匹配则返回位置, 否则返回0
int Index(String S, String T, int pos);

// 操作: 用V替换主串S中出现的所有与T相等的不重叠的子串
// 前提条件: 串S, T和V存在, T是非空串
// 后置条件: 返回一共替换的个数, 错误返回负数
int Replace(String S, String T, String V);

// 操作: 在串的第pos个字符之前插入串T
// 前提条件: 串S和T存在, 1<=pos<=StrLength(S)+1
// 后置条件: 成功返回true, 否则返回false
bool StrInsert(String S, int pos, String T);

// 操作: 从串S中删除第pos个字符起长度为len的子串
// 前提条件: 串S存在, 1<=pos<=StrLength(S)-len+1
// 后置条件: 成功返回true, 否则返回false
bool StrDelete(String S, int pos, int len);

#endif