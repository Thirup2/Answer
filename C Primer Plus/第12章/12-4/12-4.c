#include <stdio.h>
static int count=0;
int re_count(void);
int main(void)
{
    for(int i=0;i<100;i++){
        printf("The function run_time run %d times.\n",re_count());
    }

    return 0;
}
int re_count(void)
{
    count++;

    return count;
}