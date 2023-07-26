#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned int a = -1;
    signed int b = a / 2;
    unsigned char c = 255;
    cout << "a = " << a << "; b = " << b << "; c = " << static_cast<int>(c) << endl;
    cout << "a + 1 = " << a + 1 << "; b + 1 = " << b + 1 << "; c + 1 = " << static_cast<int>((static_cast<unsigned char>(c + 1))) << endl;

    return 0;
}