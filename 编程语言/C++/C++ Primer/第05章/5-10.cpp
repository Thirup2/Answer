#include <iostream>
using namespace std;
int main(void)
{
    char ch;
    int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
    while (cin >> ch) {
        switch (ch) {
            case 'A':
            case 'a':
                ++a_cnt;
                break;
            case 'E':
            case 'e':
                ++e_cnt;
                break;
            case 'I':
            case 'i':
                ++i_cnt;
                break;
            case 'O':
            case 'o':
                ++o_cnt;
                break;
            case 'U':
            case 'u':
                ++u_cnt;
                break;
        }
    }
    cout << "元音字母一共有" << a_cnt + e_cnt + i_cnt + o_cnt + u_cnt << "个" << endl;
    cout << "其中含" << endl << a_cnt << "个A/a字母" << endl;
    cout << e_cnt << "个E/e字母" << endl;
    cout << i_cnt << "个I/i字母" << endl;
    cout << o_cnt << "个O/o字母" << endl;
    cout << u_cnt << "个U/u字母" << endl;

    return 0;
}