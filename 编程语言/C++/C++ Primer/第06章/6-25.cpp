#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Please enter with two string again" << endl;
        return 0;
    }
    string str1 = argv[1];
    string str2 = argv[2];
    cout << str1 + str2 << endl;
    return 0;
}