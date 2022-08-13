#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main()
{
    string word;
    vector<string> text;
    while (cin >> word) {
        text.push_back(word);
    }
    for (auto s : text) {
        cout << s << endl;
    }

    return 0;
}