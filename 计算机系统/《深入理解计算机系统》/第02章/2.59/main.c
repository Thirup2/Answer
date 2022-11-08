#include <stdio.h>
int main(void)
{
    int cover_x = 0x000000ff;
    int cover_y = 0xffffff00;
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int result = (x & cover_x) | (y & cover_y);
    printf("%#x\n", result);

    return 0;
}