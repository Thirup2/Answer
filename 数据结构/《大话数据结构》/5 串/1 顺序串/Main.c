/* 字符串驱动程序 */
/* 包含头文件 */
#include "String.h"

/* 测试模块 */
void ShowString(CSTRING string);

/* 主函数 */
int main(void)
{
    STRING srcstr = StrAssign("this is the first string.");
    ShowString(srcstr);
    STRING concat = StrAssign(" and this is the second.\n");
    ShowString(concat);
    STRING strcopy = StrCopy(srcstr);
    ShowString(strcopy);
    STRING src_concat_str = Concat(srcstr, concat);
    ShowString(src_concat_str);
    printf("(%d)-(%d)-(%d)\n", StrCompare(srcstr, strcopy), StrCompare(srcstr, concat), StrCompare(srcstr, src_concat_str));
    STRING substr1 = SubString(strcopy, 1, 4);
    ShowString(substr1);
    STRING substr2 = SubString(strcopy, 5, 5);
    ShowString(substr2);
    STRING replace = StrAssign("that");
    ShowString(replace);
    STRING replace2 = StrAssign("-is-t");
    ShowString(replace2);
    Replace(srcstr, substr1, replace);
    ShowString(srcstr);
    Replace(strcopy, substr2, replace2);
    ShowString(strcopy);
    ClearString(concat);
    ShowString(concat);

    DestroyString(srcstr);
    DestroyString(concat);
    DestroyString(strcopy);
    DestroyString(src_concat_str);
    DestroyString(substr1);
    DestroyString(substr2);
    DestroyString(replace);
    DestroyString(replace2);

    return 0;
}

/* 测试模块定义 */
void ShowString(CSTRING string)
{
    printf(">> 字符串：\n");
    printf("    >> 是否为空：%s\n", StringEmpty(string) ? "是" : "否");
    printf("    >> 字符串长度：%d\n", StrLength(string));
    printf("    >> 字符串内容：");
    PrintString(string);
    printf("\n");
}