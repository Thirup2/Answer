#include<stdio.h>
int main()
{
    char color[5] = {'S','H','C','D','J'};
    int P = 54;
    int start[P], end[P], operate[P];
    int K, i;
        for (i = 0; i < P; i++)
        {
            start[i] = i + 1;
        }
        scanf("%d", &K);
        for (i = 0; i < P; i++)
        {
            scanf("%d", &operate[i]);
        }
    for (int step = 0; step < K; step++)
    {
        for (i = 0; i < P; i++)
        {
            end[operate[i] - 1] = start[i];
        }
        for (i = 0; i < P; i++)
        {
            start[i] = end[i];
        }
    }
        for (i = 0; i < P; i++)
    {
        start[i]--;
        if (i != 0)printf(" ");
        printf("%c%d", color[start[i] / 13], start[i] % 13 + 1);
    }
    return 0;
}