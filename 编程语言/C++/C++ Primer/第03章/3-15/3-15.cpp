#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main(void)
{
    string c;
    vector<string> text;
    while (cin >> c) {
        text.push_back(c);
    }
    
    return 0;
}