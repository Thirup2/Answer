#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int grade;
    string finalgrade;
    while (cin >> grade) {
        finalgrade = (grade >= 90) ? "high pass" :
            (grade >= 75) ? "pass" :
            (grade >= 60) ? "low pass" : "fail";
        cout << finalgrade << endl;
    }
    cout << "bye" << endl;

    return 0;
}