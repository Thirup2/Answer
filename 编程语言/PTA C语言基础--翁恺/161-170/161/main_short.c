//帅到没朋友.
//用a[i]表示i的朋友数，为0则为帅的没朋友的人（没有朋友或者自恋狂）
#include <stdio.h>
int main()
{
    int a[1000000] = {0};
    int N, K, M;
    int i, n, m, sum = 0;//sum是标志符，一举两用，在是否输出空格和是否找到太帅的人做标记 
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        for (i = 1; i <= K; i++) {
            scanf("%d", &n);//避免有些只有一个人的朋友圈重复添加产生的影响
            if (K != 1) {
                a[n] += K;//a[n]=1;//此人不帅
            }
        }
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &m);
        if (a[m] == 0) {
            if (sum != 0) printf(" ");//按输出格式的 
            printf("%05d", m);// '%05d',输出占五位，不足者用0补位  
            a[m] = 1;//输出后，做标记，避免重复查询 
            sum++;
        }
    }
    if (sum == 0) printf("No one is handsome");
    return 0;
} //yh