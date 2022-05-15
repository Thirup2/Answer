#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    string c;
    vector<string> text;
    while (getline(cin, c)) {
        text.push_back(c);
    }
    auto i = text.begin();
    if (!text.empty()) {
        for (auto &j : *i) {
            j = toupper(j);
        }
    }
    for (auto i : text) {
        cout << i << endl;
    }

    return 0;
}