#include <stdio.h>
#define HAVE 100
#define GET 10
#define RATE 0.08
int main(void)
{
    double result;
    int year;
    for(year=0,result=HAVE;result>0;year++){
        result=result*(1+RATE)-GET;
    }
    printf("Chuckie在%d年后会取完账户的钱\n",year);

    return 0;
}