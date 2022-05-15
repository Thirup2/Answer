#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
int main(void)
{
    string c;
    vector<string> words;
    while (cin >> c) {
        words.push_back(c);
    }
    for (auto &i : words) {
        for (auto &j : i) {
            j = toupper(j);
            cout << j;
        }
        cout << endl;
    }

    return 0;
}