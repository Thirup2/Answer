#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main()
{
    int grade;
    int t, g;
    vector<string> level;
    while (cin >> grade) {
        string l;
        if (grade == 100) {
            l = "A++";
            level.push_back(l);
            continue;
        }
        t = grade / 10;
        g = grade % 10;
        if (t >= 9) {
            l += 'A';
        } else if (t >= 8) {
            l += 'B';
        } else if (t >= 7) {
            l += 'C';
        } else if (t >= 6) {
            l += 'D';
        } else {
            l += 'F';
        }
        if (g >= 8) {
            l += '+';
        } else if (g < 3) {
            l += '-';
        }
        level.push_back(l);
    }
    for (auto s : level) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}