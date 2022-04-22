#include <iostream>
int main()
{
    std::cout << "/*" << std::endl;
    std::cout << "*/" << std::endl;
    // std::cout << /* "*/" */ << std::endl;
    /* 
    ** 第三条语句错误
    ** 首先,前两个注释符将第一个引号注释掉了
    ** 但同时,导致第二个引号没有了配对的引号
    ** 所以,应该在末尾添加一个引号
    ** 正确语句如下:
    */
    std::cout << /* "*/" */" << std::endl;
    std::cout << /* "*/" /* "/*" */ << std::endl;

    return 0;
}