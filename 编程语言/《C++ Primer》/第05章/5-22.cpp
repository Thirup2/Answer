#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int get_size(void);
int main()
{
    int sz = get_size();
    while (sz <= 0) {
        sz = get_size();
    }

    return 0;
}
int get_size(void)
{
    static int i = -2;
    ++i;
    return i;
}