#include <iostream>
int main()
{
    std::cout << "第一个循环:" << std::endl;
    int sum=0;
    for(int val=50;val<=100;val++){
        sum+=val;
    }
    std::cout << "The sum of 50 to 100 is " << sum << std::endl;

    std::cout << "第二个循环" << std::endl;
    for(int i=10;i>=0;i--){
        std::cout << i << std::endl;
    }
    
    std::cout << "第三个循环" << std::endl;
    std::cout << "Please enter two integer numbers:" << std::endl;
    int n1,n2;
    std::cin >> n1 >> n2;
    for(;++n1<n2;){
        std::cout << n1 << std::endl;
    }

    return 0;
}