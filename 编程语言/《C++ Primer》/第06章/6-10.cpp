#include "head.h"
void swap(int *, int *);
int main()
{
    int v1, v2;
    cin >> v1 >> v2;
    cout << "pre: " << "v1 = " << v1 << "; v2 = " << v2 << endl;
    swap(&v1, &v2);
    cout << "now: v1 = " << v1 << "; v2 = " << v2 << endl;

    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}