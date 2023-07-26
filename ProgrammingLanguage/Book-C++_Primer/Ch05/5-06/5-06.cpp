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
        lettergrade = (grade == 100) ? scores[5] :
            ((grade < 60) ? scores[0] : scores[(grade - 50) / 10]);
        if (grade >= 60 && grade < 100) {
            lettergrade += (grade % 10 > 7) ? "+" :
                ((grade % 10 < 3) ? "-" : "");
        }
        cout << grade << ": " << lettergrade << endl;
    }

    return 0;
}