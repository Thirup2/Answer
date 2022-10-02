#include <stdio.h>
int IsIt(int year);
int main(void)
{
    int years[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
    int year, mon, day;
    int days = 0;
    scanf("%d/%d/%d", &year, &mon, &day);
    if (mon <= 2) {
        for (int i = 0; i < mon - 1; i++) {
            days += years[i];
        }
        days += day;
        printf("%d", days);
        return 0;
    }
    if (IsIt(year)) {
        years[1] = 29;
    }
    for (int i = 0; i < mon - 1; i++) {
        days += years[i];
    }
    days += day;
    printf("%d", days);
    return 0;
}
int IsIt(int year)
{
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    return 0;
}