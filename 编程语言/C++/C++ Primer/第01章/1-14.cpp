#include <iostream>
int main()
{
    for(int i=0;i==0;i++){
        std::cout << "for():" << std::endl;
        std::cout << "优点: ";
        std::cout << "结构清晰,对于有计数要求的循环很有用" << std::endl;
        std::cout << "缺点: ";
        std::cout << "对于没有计数要求的循环用处不大" << std::endl;
    }
    int n=1;
    while(n==1){
        std::cout << "while():" << std::endl;
        std::cout << "与上述相反" << std::endl;
        n=0;
    }

    return 0;
}