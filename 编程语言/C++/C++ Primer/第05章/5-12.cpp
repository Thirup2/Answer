#include <iostream>
using namespace std;
int main(void)
{
    char ch;
    int ff_cnt = 0, fl_cnt = 0, fi_cnt = 0;
    while (cin >> ch) {
        if (ch == 'f') {
            cin >> ch;
            switch (ch) {
                case 'f':
                    ++ff_cnt;
                    break;
                case 'l':
                    ++fl_cnt;
                    break;
                case 'i':
                    ++fi_cnt;
                    break;
            }
        }
    }
    cout << ff_cnt << " " << fl_cnt << " " << fi_cnt << endl;

    return 0;
}