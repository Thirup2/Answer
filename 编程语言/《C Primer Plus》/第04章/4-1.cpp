#include <iostream>
#include <string>
int main()
{
    std::string fname;
    std::string lname;
    std::cout << "请输入您的姓名: " << std::endl;
    std::cin >> fname >> lname;
    std::cout << lname << ", " << fname << std::endl;

    return 0;
}