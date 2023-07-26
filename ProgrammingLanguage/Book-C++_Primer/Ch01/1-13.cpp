#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void OneDotNine();
void OneDotTen();
void OneDotEleven();

int main()
{
    int choice;
    cout << "请选择测试序号 (109：1.9题；110：1.10题；111：1.11题) ：" << endl;
    cin >> choice;
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
            cout << "输入错误，程序已退出！" << endl;
    }
    return 0;
}

void OneDotNine()
{
    int sum = 0;
    for (int i = 50; i <= 100; i++) {
        sum += i;
    }
    cout << sum << endl;
}

void OneDotTen()
{
    for (int i = 9; i > 0; i--) {
        cout << i << endl;
    }
}

void OneDotEleven()
{
    int a, b;
    cout << "请输入两个整数 a, b (a <= b): " << endl;
    cin >> a >> b;
    if (a > b) {
        cout << "输入错误，程序已退出！" << endl;
    }
    for (int i = a; i <= b; i++) {
        cout << i << endl;
    }
}