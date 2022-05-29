#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str1;
    string str2;
    do {
        cout << "Please Enter Two Strings." << endl;
        getline(cin, str1);
        getline(cin, str2);
        cout << ((str1.size() < str2.size()) ? str1 : str2) << endl << endl;
    } while (cin);

    return 0;
}