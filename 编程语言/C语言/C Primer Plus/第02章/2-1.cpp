#include <iostream>
#include <string>
using namespace std;
int main()
{
    string fname("唐");
    string lname("传顺");
    cout << fname << lname << endl;
    cout << fname << '\n' << lname << endl;
    cout << fname;
    cout << lname << endl;

    return 0;
}