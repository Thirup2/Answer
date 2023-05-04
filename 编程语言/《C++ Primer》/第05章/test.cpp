#include <memory>
#include <iostream>
#include <new>

int main()
{
    int *pi = new int(42);
    std::unique_ptr<int> up(pi);
    std::unique_ptr<int> up2(pi);
    

    return 0;
}