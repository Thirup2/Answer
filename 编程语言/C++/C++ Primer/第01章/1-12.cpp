#include <iostream>
int main()
{
    int sum=0;
    for(int i=-100;i<=100;i++){
        sum+=i;
    }
    //可以明显看出该循环计算从-100加到100,若推断无误,编译运行的结果应该是0
    std::cout << sum << std::endl;

    return 0;
}