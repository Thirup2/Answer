/* 1.4.1节练习1.9 */
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int sum = 0;
    int i = 50;
    while (i <= 100) {
        sum += i++;
    }
    cout << sum << endl;

    return 0;
}