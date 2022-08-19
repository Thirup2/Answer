#include <stdio.h>
int main(void)
{
    double son = 1.0;
    double mother = 1.0;
    double sum = son / mother;
    int count;
    int i;
    scanf("%d", &i);
    for (count = 1; count < i; count++) {
        if (count % 2 == 0) {
            son += 1.0;
            mother += 2.0;
            sum += son / mother;
        } else {
            son += 1.0;
            mother += 2.0;
            sum -= son / mother;
        }
    }
    printf("%.3lf", sum);

    return 0;
}