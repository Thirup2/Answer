#include "head.h"
int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "参数数量错误" << endl;
        exit(EXIT_FAILURE);
    }
    string param;
    param = param + argv[1] + argv[2];
    cout << param << endl;

    return 0;
}