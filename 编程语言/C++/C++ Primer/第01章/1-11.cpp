#include <iostream>
int main()
{
    int n1,n2;
    int temp;
    std::cout << "Please enter two integer numbers:" << std::endl;
    std::cin >> n1 >> n2;
    if(n1>n2){
        temp=n1;
        n1=n2;
        n2=temp;
    }
    while(++n1<n2){
        std::cout << n1 << std::endl;
    }

    return 0;
}