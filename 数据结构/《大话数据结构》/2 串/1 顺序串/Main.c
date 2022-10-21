/* 字符串测试程序源文件Main.c, 和String.c一起编译 */

/* 包含头文件 */
#include "String.h"

/* 字符串测试模块函数原型 */
void ShowString(PtrString S);

/* 主函数 */
int main(void)
{
    PtrString S = InitString();
    PtrString S_Copy = InitString();
    PtrString T = InitString();
    PtrString M = InitString();
    ShowString(S);
    
    StrAssign(S, "this is an example line.");
    ShowString(S);
    
    StrCopy(S_Copy, S);
    ShowString(S_Copy);
    
    StrAssign(T, "exam");
    StrAssign(M, "ap");
    Replace(S, T, M);
    ShowString(S);

    SubString(T, S, 9, 8);
    ShowString(T);

    printf("%d\n", StringCompare(S, S_Copy));

    Concat(M, S, S_Copy);
    ShowString(M);

    ClearString(S);
    ShowString(S);

    ClearString(M);
    ShowString(M);

    DestroyString(S);
    DestroyString(S_Copy);
    DestroyString(T);
    DestroyString(M);

    return 0;
}

/* 字符串测试模块函数定义 */
void ShowString(PtrString S)
{
    printf("当前字符串: \n");
    printf("    >> 是否为空: ");
    printf("%s\n", StringEmpty(S) ? "是" : "否");
    printf("    >> 字符个数: ");
    printf("%d\n", StringLength(S));
    printf("    >> 字符串内容: ");
    PrintString(S);
    printf("\n");
}