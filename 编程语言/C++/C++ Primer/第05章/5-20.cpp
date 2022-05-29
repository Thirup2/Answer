#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string pre;
    bool r = false;
    if (cin >> pre) {
        string now;
        while (cin >> now) {
            if (now == pre) {
                cout << now << endl;
                r = true;
                break;
            } else {
                pre = now;
            }
        }
    }
    if (r == false) {
        cout << "No Two same word" << endl;
    }
    
    return 0;
}