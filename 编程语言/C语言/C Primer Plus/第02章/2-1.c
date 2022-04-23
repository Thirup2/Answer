#include <stdio.h>
#define F_Name "Tang"
#define L_Name "Chuanshun"
int main(void)
{
    printf("%s %s\n",L_Name,F_Name);

    printf("%s\n%s\n",L_Name,F_Name);

    printf("%s ",L_Name);
    printf("%s\n",F_Name);

    return 0;
}