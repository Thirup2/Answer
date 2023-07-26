#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 512
void written_amount(unsigned int amount, char *buffer);
void Copy_num(char *copy, unsigned int three);
void Copy_str(char *copy, const char *str);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请至少输入一个参数！\n");
        return -1;
    }
    char buffer[MAXSIZE];
    unsigned int amount;
    for (int i = 1; i < argc; i++) {
        amount = (unsigned int) atoi(argv[i]);
        written_amount(amount, buffer);
        printf("%s\n", buffer);
    }

    return 0;
}

/* 下面的是抄的，我的方法在该方法之后 */
void written_amount_copy(unsigned int amount, char *buffer)
{
    unsigned short ReverseAmount[4] = {0};
    signed char i;

    //把amount的值以1000 为基准分步存入数组ReverseAmount中
    for (i = 0; amount != 0; amount /= 1000, ++i) {
        ReverseAmount[i] = amount % 1000;
    }

    //倒序遍历ReverseAmount, 把它表示的值的文字形式存储在字符串buffer中
    char *p;
    unsigned char hundred, ten, individual;    //存储百位, 十位, 个位
    for (--i; i >= 0; --i) {
        individual = ReverseAmount[i] % 10;    //获取个位
        ReverseAmount[i] /= 10;

        ten = ReverseAmount[i] % 10;    //获取十位
        ReverseAmount[i] /= 10;

        hundred = ReverseAmount[i] % 10;    //获取百位
        ReverseAmount[i] /= 10;

        switch (hundred)    //将百位数字以文字形式写入buffer
        {
            case 0:
                break;    //如果首位是0, 就不用写入buffer了, 直接跳过
            case 1:
                p = "ONE HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;    //把ONE HUNDRED 复制到buffer, 同时buffer向后移动ONE HUNDRED 所占用的长度
            case 2:
                p = "TWO HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 3:
                p = "THREE HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 4:
                p = "FOUR HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 5:
                p = "FIVE HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 6:
                p = "SIX HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 7:
                p = "SEVEN HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 8:
                p = "EIGHT HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 9:
                p = "NINE HUNDRED ";
                while (*p != '\0') *buffer++ = *p++; break;
            default:
                exit(0);
        }

        switch (ten)    //将十位的数字以文字形式写入buffer
        {
            case 0:
                break;
            case 1:    //如果十位是1, 根据英语规则, 10 到19 每个数字都有特定英文单词与之对应, 所以这里要进入switch( individual ), 根据个位的具体值, 在buffer中写入对应的字符
                switch (individual) {
                    case 0:
                        p = "TEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 1:
                        p = "ELEVEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 2:
                        p = "TWELVE ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 3:
                        p = "THIRTEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 4:
                        p = "FOURTEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 5:
                        p = "FIFTEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 6:
                        p = "SIXTEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 7:
                        p = "SEVENTEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 8:
                        p = "EIGHTEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    case 9:
                        p = "NINETEEN ";
                        while (*p != '\0') *buffer++ = *p++; break;
                    default:
                        exit(0);
                }
                break;    //这里的breaak用来跳出switch( ten )这个选择结构, 不加break的话每次十位是1, 后面都会多出一个"TWENTY "

            case 2:
                p = "TWENTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 3:
                p = "THIRTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 4:
                p = "FORTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 5:
                p = "FIFTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 6:
                p = "SIXTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 7:
                p = "SEVENTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 8:
                p = "EIGHTY ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 9:
                p = "NINETY ";
                while (*p != '\0') *buffer++ = *p++; break;
            default:
                exit(0);
        }

        if (ten != 1)    //英语中0 ~ 20 都有特定单词与之对应, 如果之前的十位是1 的话, 在写入十位的时候就已经把个位数连带写入了, 所以当前面的十位不为1 的时候才需要写入个位
        {
            switch (individual)    //将个位数字以文字形式写入buffer
            {
                case 0:
                    break;
                case 1:
                    p = "ONE ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 2:
                    p = "TWO ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 3:
                    p = "THREE ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 4:
                    p = "FOUR ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 5:
                    p = "FIVE ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 6:
                    p = "SIX ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 7:
                    p = "SEVEN ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 8:
                    p = "EIGHT ";
                    while (*p != '\0') *buffer++ = *p++; break;
                case 9:
                    p = "NINE ";
                    while (*p != '\0') *buffer++ = *p++; break;
                default:
                    exit(0);
            }
        }

        switch (i)    //写入单位, 英语使用千进制, 所以ReverseAmount数组中的一个元素的百位, 十位, 个位都写入buffer后就要把它们的单位写进去
        {
            case 0:
                break;    //ReverAmount[0]表示的是amount十进制形式的最低三位, 所以这里不加单位
            case 1:
                p = "THOUSAND ";
                while (*p != '\0') *buffer++ = *p++; break;    //ReverseAmount[1]表示的是amount的十进制形式的低4 至低6 位, 所以这里要加单位THOUSAND
            case 2:
                p = "MILLION ";
                while (*p != '\0') *buffer++ = *p++; break;
            case 3:
                p = "BILLION ";
                while (*p != '\0') *buffer++ = *p++; break;    //i的值最大为3, 因为unsigned int 最大值是BILLION(十亿)级别的, 前面为ReverseAmount数组分配空间的时候也只是用了4 个short 类型就可以把unsigned int 能表示的最大值包括在内
            default:
                exit(0);
        }
    }

    *buffer = '\0';    //在buffer有效字符后一字节写入'\0'

    return;
}

/*
** 我的方法：
** 主要是将整个数字分为多个三位数，对于每个三位数来说，其表示不受位置的影响，为了buffer的写入位置不出错，应该返回一个字符串指针，交给主体函数复制
** 另外，在主体函数中，还需要考虑在两个三位数中间的连接词，此处进行了限制，由于最大int数为十亿级，故最大只做到十亿
** 本函数采用非递归方法实现，应该还可以用递归方法实现，递归可以更好地扩展到更大的整数类型，感兴趣的可以去试试
*/
void written_amount(unsigned int amount, char *buffer)
{
    static char *catch[4] = {"ZERO", "THOUSAND", "MILLION", "BILLION"};
    static char copy[128];
    static char *ptr_copy;
    int before = 0;         // 用来判断输入的数是不是0
    unsigned int three;
    if ((three = amount / 1000000000) != 0) {
        before++;
        Copy_num(copy, three);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
        *buffer++ = ' ';
        Copy_str(copy, catch[3]);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
        *buffer++ = ' ';
        amount %= 1000000000;
    }
    if ((three = amount / 1000000) != 0) {
        before++;
        Copy_num(copy, three);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
        *buffer++ = ' ';
        Copy_str(copy, catch[2]);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
        *buffer++ = ' ';
        amount %= 1000000;
    }
    if ((three = amount / 1000) != 0) {
        before++;
        Copy_num(copy, three);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
        *buffer++ = ' ';
        Copy_str(copy, catch[1]);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
        *buffer++ = ' ';
        amount %= 1000;
    }
    if ((three = amount % 1000) != 0) {
        before++;
        Copy_num(copy, three);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
    }
    if (before == 0) {
        Copy_str(copy, catch[0]);
        ptr_copy = copy;
        while (*ptr_copy) {
            *buffer++ = *ptr_copy++;
        }
    }
    *buffer = '\0';
}
void Copy_num(char *copy, unsigned int three)
{
    static char *hundred = "HUNDRED";
    static char *ties[] = {"TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
    static char *teens[] = {"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE", "THIRTEEN",
                            "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
    static char copy_str[16];
    static char *ptr_copy;
    unsigned int oot;
    if ((oot = three / 100) != 0) {
        Copy_str(copy_str, teens[oot - 1]);
        ptr_copy = copy_str;
        while (*ptr_copy) {
            *copy++ = *ptr_copy++;
        }
        *copy++ = ' ';
        Copy_str(copy_str, hundred);
        ptr_copy = copy_str;
        while (*ptr_copy) {
            *copy++ = *ptr_copy++;
        }
        *copy++ = ' ';
    }
    if ((oot = three % 100) == 0) {
        ;
    } else if (oot < 20) {
        Copy_str(copy_str, teens[oot - 1]);
        ptr_copy = copy_str;
        while (*ptr_copy) {
            *copy++ = *ptr_copy++;
        }
    } else {
        Copy_str(copy_str, ties[oot / 10 - 2]);
        ptr_copy = copy_str;
        while (*ptr_copy) {
            *copy++ = *ptr_copy++;
        }
        if (oot % 10 != 0) {
            *copy++ = ' ';
            Copy_str(copy_str, teens[oot % 10 - 1]);
            ptr_copy = copy_str;
            while (*ptr_copy) {
                *copy++ = *ptr_copy++;
            }
        }
    }
    *copy = '\0';
}
void Copy_str(char *copy, const char *str)
{
    while (*str) {
        *copy++ = *str++;
    }
    *copy = '\0';
}