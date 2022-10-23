#include <stdio.h>
#include <stdlib.h>
struct team
{
    int team;
    int point;
};
typedef struct team Team;
typedef Team *PtrTeam;

int LocateElem(PtrTeam array, int n, int team);
int FindMax(PtrTeam array, int n);
int main(void)
{
    int N;
    scanf("%d", &N);
    int team;
    int member;
    int point;
    int r;
    int n = 0;
    PtrTeam array = NULL;
    for (int i = 0; i < N; i++) {
        scanf("%d-%d %d", &team, &member, &point);
        r = LocateElem(array, n, team);
        if (r == -1) {
            array = (PtrTeam) realloc(array, (++n) * sizeof(Team));
            array[n - 1].team = team;
            array[n - 1].point = point;
        } else {
            array[r].point += point;
        }
    }
    r = FindMax(array, n);
    printf("%d %d\n", array[r].team, array[r].point);
    free(array);

    return 0;
}

int LocateElem(PtrTeam array, int n, int team)
{
    if (array == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (team == array[i].team) {
            return i;
        }
    }
    return -1;
}
int FindMax(PtrTeam array, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (array[i].point > array[max].point) {
            max = i;
        }
    }
    return max;
}