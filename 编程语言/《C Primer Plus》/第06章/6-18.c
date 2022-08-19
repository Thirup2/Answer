#include <stdio.h>
#define FR 5
int main(void)
{
    int weeks;
    int friends;
    for(weeks=0,friends=FR;friends<=150;weeks++){
        friends=(friends-weeks-1)*2;
    }
    printf("周数是:%d\n",weeks);

    return 0;
}