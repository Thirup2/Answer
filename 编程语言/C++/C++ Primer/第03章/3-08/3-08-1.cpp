#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(void)
{
    string line;
    getline(cin, line);
    unsigned count = 0;
    while (count < line.size()) {
        line[count] = 'X';
        count++;
    }
    cout << line << endl;
    return 0;
}