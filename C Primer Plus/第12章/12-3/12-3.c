#include "12-3.h"
int main(void)
{
    int mode=0;
    int n;
    double range,fuel;

    printf("Enter 0 for metric mode(default), 1 for US mode:");
    scanf("%d", &n);
    while (n >= 0)
    {
        set_mode(&mode,n);
        get_info(&range,&fuel,mode);
        show_info(&range,&fuel,mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &n);
    }
    printf("Done.\n");
    return 0;
}