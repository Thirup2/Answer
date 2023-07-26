#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main()
{
    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    int grade;
    while (cin >> grade) {
        if (grade > 100 || grade < 0) {
            cout << "分数输入错误，请重新输入：" << endl;
            continue;
        }
        if (grade == 100) {
            lettergrade = scores[5];
        } else if (grade < 60) {
            lettergrade = scores[0];
        } else {
            lettergrade = scores[(grade - 50) / 10];
            if (grade % 10 > 7) {
                lettergrade += '+';
            } else if (grade % 10 < 3) {
                lettergrade += '-';
            }
        }
        cout << grade << ": " << lettergrade << endl;
    }

    return 0;
}