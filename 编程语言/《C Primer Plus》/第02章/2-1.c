#include <stdio.h>
#define FNAME "唐"
#define LNAME "传顺"
int main(void)
{
    printf("%s%s\n", FNAME, LNAME);
    printf("%s\n%s\n", FNAME, LNAME);
    printf("%s", FNAME);
    printf("%s\n", LNAME);

    return 0;
}