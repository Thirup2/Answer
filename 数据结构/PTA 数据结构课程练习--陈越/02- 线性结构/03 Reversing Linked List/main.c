#include <stdio.h>
#include <stdlib.h>

struct items
{
    int address;
    int data;
    int next_add;
};
typedef struct items ElemType;


int main(void)
{
    int first, N, K;
    scanf("%d %d %d", &first, &N, &K);
    ElemType elem;
    ElemType *elem_arr = NULL;
    int n = 0;
    while ((scanf("%d %d %d", &elem.address, &elem.data, &elem.next_add)) == 3) {
        n++;
        elem_arr = (ElemType *) realloc(elem_arr, n * sizeof(ElemType));
        elem_arr[n - 1] = elem;
    }
    // 从输入中获取前N个
    ElemType *list = (ElemType *) malloc(N * sizeof(ElemType));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    int now = first;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++) {
            if (elem_arr[j].address == now) {
                list[i] = elem_arr[j];
                now = elem_arr[j].next_add;
                break;
            }
        }
    }
    list[N - 1].next_add = -1;
    free(elem_arr);
    // 转换list
    ElemType *copy = (ElemType *) malloc(N * sizeof(ElemType));
    for (int i = 0, m = 0; m < N / K; m++) {
        for (int j = (m + 1) * K - 1; j >= m * K; j--) {
            copy[i].address = list[j].address;
            copy[i].data = list[j].data;
            i++;
        }
    }
    for (int i = N / K * K; i < N; i++) {
        copy[i].address = list[i].address;
        copy[i].data = list[i].data;
    }
    for (int i = 0; i < N - 1; i++) {
        copy[i].next_add = copy[i + 1].address;
    }
    copy[N - 1].next_add = -1;

    // 输出list
    for (int i = 0; i < N - 1; i++) {
        printf("%05d %d %05d\n", copy[i].address, copy[i].data, copy[i].next_add);
    }
    printf("%05d %d %d", copy[N - 1].address, copy[N - 1].data, copy[N - 1].next_add);

    free(list);
    free(copy);

    return 0;
}