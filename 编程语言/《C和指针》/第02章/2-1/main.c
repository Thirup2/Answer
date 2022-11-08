#include <stdio.h>
int increment(int n);
int negate(int n);
int main(void)
{
    printf("x = 10, increment(x) = %d, negate(x) = %d\n", increment(10), negate(10));
    printf("y = 0, increment(y) = %d, negate(y) = %d\n", increment(0), negate(0));
    printf("z = -10, increment(z) = %d, negate(z) = %d\n", increment(-10), negate(-10));

    return 0;
}