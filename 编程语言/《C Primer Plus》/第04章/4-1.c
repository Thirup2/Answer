#include <stdio.h>
int main(void)
{
    char fname[20];
    char lname[20];
    printf("Please Enter your first name and last name: ");
    scanf("%s %s", fname, lname);
    printf("Hello, %s %s\n", lname, fname);

    return 0;
}