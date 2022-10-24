#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char num[17];
    int try;
    int sit;
};
typedef struct node Node;
typedef Node *PtrNode;

int findtry(PtrNode array, int n, int try);

int main(void)
{
    int n;
    scanf("%d", &n);
    PtrNode array = (PtrNode) malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", array[i].num, &(array[i].try), &(array[i].sit));
    }
    int k;
    scanf("%d", &k);
    int try;
    int r;
    for (int i = 0; i < k; i++) {
        scanf("%d", &try);
        r = findtry(array, n, try);
        printf("%s %d\n", array[r].num, array[r].sit);
    }
    free(array);

    return 0;
}
int findtry(PtrNode array, int n, int try)
{
    for (int i = 0; i < n; i++) {
        if (try == array[i].try) {
            return i;
        }
    }
}