#include <iostream>

void OneDotNine();
void OneDotTen();
void OneDotEleven();

int main()
{
    int choice;
    std::cout << "请选择测试序号 (109：1.9题；110：1.10题；111：1.11题) ：" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 109:
            OneDotNine();
            break;
        case 110:
            OneDotTen();
            break;
        case 111:
            OneDotEleven();
            break;
        default:
            std::cout << "输入错误，程序已退出！" << std::endl;
    }
    return 0;
}

void OneDotNine()
{
    int sum = 0;
    for (int i = 50; i <= 100; i++) {
        sum += i;
    }
    std::cout << sum << std::endl;
}

void OneDotTen()
{
    for (int i = 9; i > 0; i--) {
        std::cout << i << std::endl;
    }
}

void OneDotEleven()
{
    int a, b;
    std::cout << "请输入两个整数 a, b (a <= b): " << std::endl;
    std::cin >> a >> b;
    if (a > b) {
        std::cout << "输入错误，程序已退出！" << std::endl;
    }
    for (int i = a; i <= b; i++) {
        std::cout << i << std::endl;
    }
}