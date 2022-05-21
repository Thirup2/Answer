#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int grade;
    string finalgrade;
    while (cin >> grade) {
        if (grade >= 90) {
            finalgrade = "high pass";
        } else if (grade >= 75) {
            finalgrade = "pass";
        } else if (grade >= 60) {
            finalgrade = "low pass";
        } else {
            finalgrade = "fail";
        }
        cout << finalgrade << endl;
    }
    cout << "bye" << endl;

    return 0;
}