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
    level = (grade >= 90) ? "high pass" : (grade >= 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
}