#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请指示使用哪种初始化方式(输入数字1或2)\n");
        return -1;
    }
    int a = atoi(argv[1]);
    if (a == 1) {
        unsigned char char_value[3][6][4][5] = {
        [1] = {
            [1] = {
                [1] = {
                    [1] = ' '
                }
            },
            [2] = {
                [2] = {
                    [3] = 'A'
                },
                [3] = {
                    [4] = 'x'
                }
            },
            [3] = {
                [2] = {
                    [2] = 0xf3
                }
            },
            [4] = {
                [2] = {
                    [3] = '\n'
                }
            }
        },
        [2] = {
            [1] = {
                [1] = {
                    [2] = 0320
                }
            },
            [2] = {
                [1] = {
                    [1] = '0'
                },
                [2] = {
                    [2] = '\''
                },
                [3] = {
                    [1] = '\121'
                }
            },
            [4] = {
                [3] = {
                    [2] = '3',
                    [3] = 3
                }
            },
            [5] = {
                [3] = {
                    [4] = 125
                }
            }
        }
        };
        for (int i = 0; i < 3; i++) {
            printf("第%d个:\n", i);
            for (int j = 0; j < 6; j++) {
                printf("  第%d层:\n", j);
                for (int m = 0; m < 4; m++) {
                    printf("    第%d行:\n", m);
                    for (int n = 0; n < 5; n++) {
                        printf("      第%d列: ", n);
                        printf("%#-5x", char_value[i][j][m][n]);
                    }
                    printf("\n");
                }
            }
        }
    } else if (a == 2) {
        unsigned char char_value[3][6][4][5] = {
            [1][2][2][3] = 'A',
            [2][4][3][2] = '3',
            [2][4][3][3] = 3,
            [2][1][1][2] = 0320,
            [1][1][1][1] = ' ',
            [1][4][2][3] = '\n',
            [2][5][3][4] = 125,
            [2][2][2][2] = '\'',
            [1][3][2][2] = 0xf3,
            [2][2][3][1] = '\121',
            [1][2][3][4] = 'x',
            [2][2][1][1] = '0'
        };
        for (int i = 0; i < 3; i++) {
            printf("第%d个:\n", i);
            for (int j = 0; j < 6; j++) {
                printf("  第%d层:\n", j);
                for (int m = 0; m < 4; m++) {
                    printf("    第%d行:\n", m);
                    for (int n = 0; n < 5; n++) {
                        printf("      第%d列: ", n);
                        printf("%#-5x", char_value[i][j][m][n]);
                    }
                    printf("\n");
                }
            }
        }
    }

    return 0;
}