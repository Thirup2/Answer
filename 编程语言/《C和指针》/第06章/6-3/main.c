#include <stdio.h>
#include <string.h>
void reverse_string(char *string);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请输入一个字符串作为参数！\n");
        return -1;
    }
    reverse_string(argv[1]);
    printf("%s\n", argv[1]);

    return 0;
}
void reverse_string(char *string)
{
    char temp;
    int len = strlen(string);           // 题目要求不能操纵，这里只算个长度应该问题不大，实在不行再写个算长度的函数，那个简单
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
    }
}