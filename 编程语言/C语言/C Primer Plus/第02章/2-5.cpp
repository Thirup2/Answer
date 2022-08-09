#include <iostream>
using namespace std;
void br(void);
void ic(void);
int main(void)
{
    br();
    cout << ", ";
    ic();
    ic();
    br();

    return 0;
}
void br(void)
{
    cout << "Brazil, Russia";
}
void ic(void)
{
    cout << "India, China" << endl;
}