#include <iostream>
#include <string>
#include <vector>
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
    for (auto &i : text) {
        for (auto &s : i) {
            s = toupper(s);
        }
    }
    for (auto i : text) {
        cout << i << endl;
    }

    return 0;
}