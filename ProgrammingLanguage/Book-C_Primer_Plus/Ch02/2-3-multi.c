#include <stdio.h>
#include <time.h>       // 获取当前本地时间

#define DPY 365
#define BORN_YEAR 2002  // 出生年份
#define BORN_MONTH 3    // 出生月份
#define BORN_DAYS 16    // 出生日期
#define BASE_YEAR 2000

int main(void)
{
    time_t now;                             // 1970-1-1 00:00:00 以来的总秒数
    struct tm *tm_now;                      // 结构化时间（其中年份需要加上1900才是正常年份）
    time(&now);                             // 获取现在时间，time_t 类型
    tm_now = localtime(&now);               // 将time_t类型时间转换为结构化时间
    int now_year = tm_now->tm_year + 1900;  // 获取现在的年份
    int now_mont = tm_now->tm_mon + 1;      // 获取现在的月份（因为从数组0位置开始存所以加1）
    int now_mday = tm_now->tm_mday;         // 获取现在的日期

    // 每月天数
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 差值
    int diff_year = now_year - BORN_YEAR;
    int diff_mont = now_mont - BORN_MONTH;
    int diff_days = now_mday - BORN_DAYS;

    // 计算年龄
    int age, days;
    age = diff_year;
    if (diff_mont < 0 || (diff_mont == 0 || diff_days < 0)) {
        age--;
    }

    // 计算天数
    int now_days;
    now_days = (now_year - BASE_YEAR) * DPY;
    for (int i = 1; i < now_mont; i++) {
        now_days += month_days[i - 1];
    }
    now_days += now_mday;

    int born_days;
    born_days = (BORN_YEAR - BASE_YEAR) * DPY;
    for (int i = 1; i < BORN_MONTH; i++) {
        born_days += month_days[i - 1];
    }
    born_days += BORN_DAYS;

    days = now_days - born_days;

    printf("Now I'm %d ages and it's %d days.\n", age, days);

    return 0;
}