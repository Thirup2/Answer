#include <stdio.h>
#include <string.h>
#include <ctype.h>
int WhatType(char string[]);
int main(void)
{
    char string[81];
    char buffer[10];
    int N;
    int r;
    char ch;
    int j = 0;
    scanf("%d", &N);
    while (getchar() != '\n') {
        continue;
    }
    for (int i = 0; i < N; i++) {
        while ((ch = getchar()) != '\n') {
            string[j++] = ch;
        }
        string[j] = '\0';
        r = WhatType(string);
        if (r == 1) {
            printf("Your password is wan mei.\n");
        } else if (r == 2) {
            printf("Your password is tai duan le.\n");
        } else if (r == 3) {
            printf("Your password is tai luan le.\n");
        } else if (r == 4) {
            printf("Your password needs shu zi.\n");
        } else if (r == 5) {
            printf("Your password needs zi mu.\n");
        }
        j = 0;
    }

    return 0;
}
int WhatType(char string[])
{
    if (strlen(string) < 6) {
        return 2;
    }
    int cnt_al = 0;
    int cnt_nu = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if ((!isalpha(string[i])) && (!isdigit(string[i])) && string[i] != '.') {
            return 3;
        }
        if (isalpha(string[i])) {
            cnt_al++;
        }
        if (isdigit(string[i])) {
            cnt_nu++;
        }
    }
    if (!cnt_nu) {
        return 4;
    }
    if (!cnt_al) {
        return 5;
    }
    return 1;
}