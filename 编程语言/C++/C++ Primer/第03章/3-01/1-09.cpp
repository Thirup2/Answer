#include <iostream>
using std::cout;
using std::endl;
int main(void)
{
    int sum = 0;
    int count = 50;
    while (count <= 100) {
        sum += count;
        count++;
    }
    
    cout << "一共是: " << sum << endl;

    return 0;
}