#include <stdio.h>
int main(void)
{
    int N;
    double H;
    double W;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &H, &W);
        W = W / 2;
        int Standard;
        Standard = (H - 100) * 0.9;
        if (W > Standard) {
            if (W - Standard < Standard * 0.1) {
                printf("You are wan mei!\n");
            } else {
                printf("You are tai pang le!\n");
            }
        } else {
            if (Standard - W < Standard * 0.1) {
                printf("You are wan mei!\n");
            } else {
                printf("You are tai shou le!\n");
            }
        }
    }
    return 0;
}