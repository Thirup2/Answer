#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    string v1, v2;
    do {
        cin >> v1 >> v2;
        cout << (v1.size() < v2.size() ? v1 : v2) << endl;
    } while (cin);

    return 0;
}