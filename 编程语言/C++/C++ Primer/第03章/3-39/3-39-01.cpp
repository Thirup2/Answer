#include <iostream>
using namespace std;
int main(void)
{
    string str1;
    string str2;
    getline(cin, str1);
    getline(cin, str2);
    if (str1 < str2) {
        cout << "The bigger is str2" << endl;
    } else if (str1 > str2) {
        cout << "The bigger is str1" << endl;
    } else {
        cout << "The two string is same" << endl;
    }

    return 0;
}