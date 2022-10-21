#include <stdio.h>
int main(void)
{
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    int t_hh = hh, t_mm = mm;
    if (t_mm != 0) {
        t_hh++;
    }
    int count = t_hh - 12;
    if (count <= 0) {
        printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
        return 0;
    } else {
        for (int i = 1; i <= count; ++i) {
            printf("Dang");
        }
    }
    return 0;
}