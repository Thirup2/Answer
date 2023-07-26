#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    vector<unsigned>::iterator ite_sco = scores.begin();
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100) {
            ++(*(ite_sco + (grade / 10)));
        }
    }
    for (unsigned now : scores) {
        cout << now << " ";
    }
    cout << endl;

    return 0;
}