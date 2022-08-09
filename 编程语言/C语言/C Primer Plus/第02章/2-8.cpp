#include <iostream>
using namespace std;
void one_three(void);
void two(void);
int main()
{
    cout << "starting now:" << endl;
    one_three();
    cout << "done!" << endl;
}
void one_three(void)
{
    cout << "one" << endl;
    two();
    cout << "three" << endl;
}
void two(void)
{
    cout << "two" << endl;
}