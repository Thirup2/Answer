#include <iostream>
using namespace std;
void print_num(const int &a);
void print_arr(const int(&arr)[2]);
int main(void)
{
    int i = 0;
    int j[2] = {0, 1};
    print_num(i);
    print_arr(j);
    return 0;
}
void print_num(const int &a)
{
    cout << a << endl;
}
void print_arr(const int(&arr)[2])
{
    for (auto num : arr) {
        cout << num << " ";
    }
    cout << endl;
}