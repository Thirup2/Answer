#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// #define BIT
#ifdef BIT
#define TIMES *8
#else
#define TIMES
#endif
int main()
{
    cout << "sizeof(bool) = " << sizeof(bool) TIMES << endl;
    cout << "sizeof(char) = " << sizeof(char) TIMES << endl;
    cout << "sizeof(wchar_t) = " << sizeof(wchar_t) TIMES << endl;
    cout << "sizeof(char16_t) = " << sizeof(char16_t) TIMES << endl;
    cout << "sizeof(char32_t) = " << sizeof(char32_t) TIMES << endl;
    cout << "sizeof(short) = " << sizeof(short) TIMES << endl;
    cout << "sizeof(int) = " << sizeof(int) TIMES << endl;
    cout << "sizeof(long) = " << sizeof(long) TIMES << endl;
    cout << "sizeof(long long) = " << sizeof(long long) TIMES << endl;
    cout << "sizeof(float) = " << sizeof(float) TIMES << endl;
    cout << "sizeof(double) = " << sizeof(double) TIMES << endl;
    cout << "sizeof(long double) = " << sizeof(long double) TIMES << endl;

    return 0;
}