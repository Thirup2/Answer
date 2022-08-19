#include <iostream>
using namespace std;
void jolly(void);
void deny(void);
int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();

    return 0;
}
void jolly(void)
{
    cout << "For he's a jolly good fellow!" << endl;
}
void deny(void)
{
    cout << "Which nobody can deny!" << endl;
}