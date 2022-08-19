#include <iostream>
#include <string>
using namespace std;
int main()
{
    string smi("Smile!");
    cout << smi << smi << smi << '\n'
        << smi << smi << '\n'
        << smi << endl;

    return 0;
}