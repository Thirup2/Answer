#include <stdio.h>
#include <stdlib.h>
struct items
{
    int tag;
    int cnt;
};
typedef struct items ElemType;

int LocateTag(ElemType *array, int n, int tag);
int Maxtag(ElemType *array, int n);
int main(void)
{
    ElemType *array = NULL;
    int n = 0;
    int N;
    int tag;
    int location;
    scanf("%d", &N);
    int k;
    for (int i = 0; i < N; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &tag);
            location = LocateTag(array, n, tag);
            if (location == -1) {
                n++;
                array = (ElemType *) realloc(array, n * sizeof(ElemType));
                array[n - 1].cnt = 1;
                array[n - 1].tag = tag;
            } else {
                array[location].cnt++;
            }
        }
    }
    int max = Maxtag(array, n);
    printf("%d %d", array[max].tag, array[max].cnt);
    free(array);

    return 0;
}

int LocateTag(ElemType *array, int n, int tag)
{
    if (array == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (array[i].tag == tag) {
            return i;
        }
    }
    return -1;
}
int Maxtag(ElemType *array, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (array[i].cnt > array[max].cnt) {
            max = i;
        } else if (array[i].cnt == array[max].cnt) {
            max = array[i].tag > array[max].tag ? i : max;
        }
    }
    return max;
}