#include <iostream>
using namespace std;
void swap(int *, int *);
int main(void)
{
    int a, b;
    while (cin >> a >> b) {
        swap(&a, &b);
        cout << "a = " << a << ", " << "b = " << b << endl;
    }
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}