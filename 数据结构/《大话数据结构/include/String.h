/* 顺序串接口头文件 */
#ifndef _STRING_H_
#define _STRING_H_

/* 包含头文件 */
#include "Status.h"
#include <stdbool.h>

/* 兼容配置 */
#ifdef WIN32
#ifdef EXPORT
#define String_API _declspec(dllexport)
#else
#define String_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define String_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 顺序串类型定义 */
typedef char CHAR;
typedef char *PCHAR;
typedef const char *CPCHAR;

typedef PCHAR STRING;
typedef CPCHAR CSTRING;

typedef signed char size_char;
#define MAXSIZE 127

/* 顺序串函数接口 */

/*
** 操作：根据字符串常量生成字符串
** 参数：字符串常量
** 返回值：生成的字符串
*/
String_API STRING DLL_CALL StrAssign(CPCHAR chars);

/*
** 操作：根据字符串生成字符串
** 参数：字符串
** 返回值：新生成的字符串
*/
String_API STRING DLL_CALL StrCopy(CSTRING string);

/*
** 操作：清空字符串
** 参数：字符串
*/
String_API void DLL_CALL ClearString(STRING string);

/*
** 操作：销毁字符串
** 参数：字符串
*/
String_API void DLL_CALL DestroyString(STRING string);

/*
** 操作：判断字符串是否为空
** 参数：字符串
** 返回值：
** 1. 若字符串为空返回true
** 2. 否则返回false
*/
String_API bool DLL_CALL StringEmpty(CSTRING string);

/*
** 操作：返回字符串的长度
** 参数：字符串
** 返回值：字符串长度
*/
String_API size_char DLL_CALL StrLength(CSTRING string);

/*
** 操作：比较两个字符串
** 参数：两个待比较的字符串
** 返回值：
** 1. 若第一个字符串大于第二个字符串，则返回值大于0
** 2. 若第一个字符串等于第二个字符串，则返回值等于0
** 3. 若第一个字符串小于第二个字符串，则返回值小于0
*/
String_API size_char DLL_CALL StrCompare(CSTRING str1, CSTRING str2);

/*
** 操作：连接两个字符串
** 参数：
** 1. 结果字符串的前段
** 2. 结果字符串的后段
** 返回值：连接后的字符串
*/
String_API STRING DLL_CALL Concat(CSTRING str1, CSTRING str2);

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
String_API STRING DLL_CALL SubString(CSTRING string, size_char pos, size_char len);

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
String_API size_char DLL_CALL Index(CSTRING string, CSTRING substring, size_char pos);

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
String_API Status DLL_CALL Replace(STRING string, CSTRING substring, CSTRING restring);

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
String_API Status DLL_CALL StrInsert(STRING string, size_char pos, CSTRING substring);

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
String_API Status DLL_CALL StrDelete(STRING string, size_char pos, size_char len);

/*
** 操作：打印字符串
** 参数：字符串
*/
String_API void DLL_CALL PrintString(CSTRING string);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif
