#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42;

    auto j = i;                     // j(int)
    const auto &k = i;              // k(const int &)
    auto *p = &i;                   // p(int *)
    const auto j2 = i, &k2 = i;     // j2(const int), k2(const int &)

    return 0;
}