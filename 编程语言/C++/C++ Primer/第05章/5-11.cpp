#include <iostream>
using namespace std;
int main(void)
{
    char ch;
    int i_cnt = 0, b_cnt = 0, t_cnt = 0, n_cnt = 0;
    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
                ++i_cnt;
                break;
            case ' ':
                ++b_cnt;
                break;
            case '\t':
            case '\r':
                ++t_cnt;
                break;
            case '\n':
                ++n_cnt;
                break;
        }
    }
    cout << "元音字符个数: " << i_cnt << endl;
    cout << "空格字符个数: " << b_cnt << endl;
    cout << "制表字符个数: " << t_cnt << endl;
    cout << "换行字符个数: " << n_cnt << endl;

    return 0;
}