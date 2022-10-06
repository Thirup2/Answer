#include <stdio.h>
#define Apple 3.00
#define Pear 2.50
#define Orange 4.10
#define Grape 10.20
void show_menu(void);
int main(void)
{
    show_menu();
    int count = 0;
    int n;
    double price;
    while (scanf("%d", &n) == 1) {
        ++count;
        if (count > 5) {
            break;
        }
        switch (n) {
            case 1:
                price = Apple;
                break;
            case 2:
                price = Pear;
                break;
            case 3:
                price = Orange;
                break;
            case 4:
                price = Grape;
                break;
            case 0:
                return 0;
            default:
                price = 0.0;
                break;
        }
        printf("price = %.2lf\n", price);
    }
    return 0;
}
void show_menu(void)
{
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
}