#include <iostream>
#include <string>
using std::getline;
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string line;
    getline(cin, line);
    cout << line << endl;
    cin >> line;
    cout << line << endl;

    return 0;
}