#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    string lettergrade;
    int grade;
    while (cin >> grade) {
        lettergrade = ((grade < 60) ? scores[0] :
                       (scores[(grade - 50) / 10] + ((grade == 100) ? "" :
                                                     ((grade % 10 > 7) ? "+" :
                                                      ((grade % 10 < 3) ? "-" : "")
                                                      )
                                                     )
                        )
                       );
        cout << "Your level is " << lettergrade << endl;
    }

    return 0;
}