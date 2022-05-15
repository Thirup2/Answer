#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string line;
    getline(cin, line);
    for (int count = 0; count < line.size(); count++) {
        line[count] = 'X';
    }
    cout << line << endl;

    return 0;
}