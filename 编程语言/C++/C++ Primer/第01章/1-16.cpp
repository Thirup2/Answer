#include <iostream>
int main()
{
    int sum=0;
    int value=0;
    while(std::cin >> value){
        sum+=value;
    }
    std::cout << "The sum of your enter is : " << sum << std::endl;

    return 0;
}