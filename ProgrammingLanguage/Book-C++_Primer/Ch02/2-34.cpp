#include <iostream>

int main()
{
    int i = 0, &r = i;
    auto a = r;         // int a = r;
    const int ci = i, &cr = ci;
    auto b = ci;        // int b = ci;
    auto c = cr;        // int c = ci;
    auto d = &i;        // int *d = &i;
    auto e = &ci;       // const int *e = &ci;
    auto &g = ci;       // const int &g = ci;

    std::cout << "a = " << a << "; b = " << b << "; c = " << c << "; d = " << d << "; e = " << e << "; g = " << g << std::endl;
    
    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // g = 42;

    std::cout << "a = " << a << "; b = " << b << "; c = " << c << "; d = " << d << "; e = " << e << "; g = " << g << std::endl;

    return 0;
}