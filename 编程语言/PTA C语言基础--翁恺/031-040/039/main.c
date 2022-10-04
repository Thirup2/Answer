#include <stdio.h>
#define CHECK 10
#define REST 30
int main(void)
{
    int T;
    int S_Gui = 0;
    int S_Tu = 0;
    scanf("%d", &T);
    while (T >= 30) {
        if (S_Gui >= S_Tu) {
            T -= CHECK;
            S_Gui += CHECK * 3;
            S_Tu += CHECK * 9;
        } else {
            T -= REST;
            S_Gui += REST * 3;
        }
    }
    while (S_Gui >= S_Tu && T >= 10) {
        S_Gui += 10 * 3;
        S_Tu += 10 * 9;
        T -= 10;
    }
    if (S_Gui < S_Tu) {
        S_Gui += T * 3;
        T = 0;
    } else {
        S_Tu += T * 9;
        S_Gui += T * 3;
        T = 0;
    }
    if (S_Gui > S_Tu) {
        printf("@_@ %d", S_Gui);
    } else if (S_Gui == S_Tu) {
        printf("-_- %d", S_Gui);
    } else {
        printf("^_^ %d", S_Tu);
    }

    return 0;
}