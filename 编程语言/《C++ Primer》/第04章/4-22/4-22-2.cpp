#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

void getlevel(int grade, string &level);
int main()
{
    string level;
    int grade;
    while (cin >> grade) {
        getlevel(grade, level);
        cout << level << endl;
    }

    return 0;
}
void getlevel(int grade, string &level)
{
    if (grade >= 90) {
        level = "high pass";
    } else if (grade >= 75) {
        level = "pass";
    } else if (grade >= 60) {
        level = "low pass";
    } else {
        level = "fail";
    }
}