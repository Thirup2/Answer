#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    auto a = r;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;

    std::cout << "i: " << i
        << "; r: " << r
        << "; ci: " << ci
        << "; cr: " << cr
        << "; a: " << a
        << "; b: " << b
        << "; c: " << c
        << "; d: " << d
        << "; e: " << e
        << "; g: " << g
        << std::endl;
    
    std::cout << "EXEC: a = 42;" << std::endl;
    a = 42;
    std::cout << "i: " << i
        << "; r: " << r
        << "; ci: " << ci
        << "; cr: " << cr
        << "; a: " << a
        << "; b: " << b
        << "; c: " << c
        << "; d: " << d
        << "; e: " << e
        << "; g: " << g
        << std::endl;

    std::cout << "EXEC: b = 42;" << std::endl;
    b = 42;
    std::cout << "i: " << i
        << "; r: " << r
        << "; ci: " << ci
        << "; cr: " << cr
        << "; a: " << a
        << "; b: " << b
        << "; c: " << c
        << "; d: " << d
        << "; e: " << e
        << "; g: " << g
        << std::endl;

    std::cout << "EXEC: c = 42;" << std::endl;
    c = 42;
    std::cout << "i: " << i
        << "; r: " << r
        << "; ci: " << ci
        << "; cr: " << cr
        << "; a: " << a
        << "; b: " << b
        << "; c: " << c
        << "; d: " << d
        << "; e: " << e
        << "; g: " << g
        << std::endl;

    // std::cout << "EXEC: d = 42;" << std::endl;
    // d = 42;
    // std::cout << "i: " << i
    //     << "; r: " << r
    //     << "; ci: " << ci
    //     << "; cr: " << cr
    //     << "; a: " << a
    //     << "; b: " << b
    //     << "; c: " << c
    //     << "; d: " << d
    //     << "; e: " << e
    //     << "; g: " << g
    //     << std::endl;

    // std::cout << "EXEC: e = 42;" << std::endl;
    // e = 42;
    // std::cout << "i: " << i
    //     << "; r: " << r
    //     << "; ci: " << ci
    //     << "; cr: " << cr
    //     << "; a: " << a
    //     << "; b: " << b
    //     << "; c: " << c
    //     << "; d: " << d
    //     << "; e: " << e
    //     << "; g: " << g
    //     << std::endl;

    // std::cout << "EXEC: g = 42;" << std::endl;
    // g = 42;
    // std::cout << "i: " << i
    //     << "; r: " << r
    //     << "; ci: " << ci
    //     << "; cr: " << cr
    //     << "; a: " << a
    //     << "; b: " << b
    //     << "; c: " << c
    //     << "; d: " << d
    //     << "; e: " << e
    //     << "; g: " << g
    //     << std::endl;

    return 0;
}