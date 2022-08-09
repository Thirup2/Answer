#include <iostream>
using namespace std;
int main(void)
{
    const int DPY = 365;
    int age;
    cout << "请输入您的年龄: ";
    cin >> age;
    cout << "您的年龄对应的天数是: " << age * DPY << endl;

    return 0;
}