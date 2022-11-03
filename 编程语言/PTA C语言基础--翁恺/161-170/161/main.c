#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct team_list
{
    int team_No;            // 朋友圈编号
    int team_Mem;           // 朋友圈里的人数
    struct team_list *next;  // 下一个朋友圈
};
typedef struct team_list Team;
typedef Team *PtrTeam;

struct person
{
    int Per_No;         // 人的编号
    int team_Num;       // 加入的队伍个数
    PtrTeam team_list;  // 朋友圈表
    int IsntSearch;     // 判断是否被搜索过, 默认为0(否)
};
typedef struct person Member;
typedef Member *PtrMember;

/*
** 操作: 判断当前成员是否存在
** 参数:
** 1. 成员数组
** 2. 数组大小
** 3. 待查成员
** 返回值:
** 1. 若数组为空, 返回-1
** 2. 若成员不存在, 返回-1
** 3. 若成员存在, 返回其下标
*/
int IsItIn(PtrMember array, int size, int Mem_No);

/*
** 操作: 给指定成员添加一个队伍, 队伍长度加1
** 参数:
** 1. 成员数组
** 2. 指定成员位置
** 3. 队伍编号i
** 4. 队伍长度K
*/
void InsertTeam(PtrMember array, int mem_pos, int team_No, int team_len);

/*
** 操作: 判断是否是太帅而没有朋友, 判断完之后改为1
** 参数:
** 1. 成员数组
** 2. 数组大小
** 3. 待判断成员
** 返回值:
** 1. 若数组中没有该成员返回-1
** 2. 若该成员没有一个team人数超过1返回-2
** 3. 其他情况返回0
*/
int NoFriend(PtrMember array, int size, int Mem_No);

/*
** 操作: 销毁成员表
** 参数:
** 1. 成员数组
** 2. 数组大小
*/
void DestroyArray(PtrMember array, int size);

/* 主函数 */
int main(void)
{
    int N;
    scanf("%d", &N);
    int K;
    PtrMember array = NULL;
    int size = 0;
    int r;
    int Mem_No;
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &Mem_No);
            r = IsItIn(array, size, Mem_No);
            if (r == -1) {
                array = (PtrMember) realloc(array, ++size * sizeof(Member));
                array[size - 1].Per_No = Mem_No;
                array[size - 1].IsntSearch = 0;
                array[size - 1].team_Num = 0;
                array[size - 1].team_list = NULL;
                InsertTeam(array, size - 1, i, K);
            } else {
                InsertTeam(array, r, i, K);
            }
        }
    }
    int M;
    int ret;
    int cnt = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &Mem_No);
        ret = NoFriend(array, size, Mem_No);
        if (ret == -1) {
            array = (PtrMember) realloc(array, ++size * sizeof(Member));
            array[size - 1].IsntSearch = 1;
            array[size - 1].Per_No = Mem_No;
            array[size - 1].team_list = NULL;
            array[size - 1].team_Num = 0;
            if (cnt == 0) {
                printf("%05d", Mem_No);
            } else {
                printf(" %05d", Mem_No);
            }
            cnt++;
        } else if(ret==-2){
            if (cnt == 0) {
                printf("%05d", Mem_No);
            } else {
                printf(" %05d", Mem_No);
            }
            cnt++;
        }
    }
    if (cnt == 0) {
        printf("No one is handsome");
    }
    DestroyArray(array, size);

    return 0;
}

/*
** 操作: 判断当前成员是否存在
** 参数:
** 1. 成员数组
** 2. 数组大小
** 3. 待查成员
** 返回值:
** 1. 若数组为空, 返回-1
** 2. 若成员不存在, 返回-1
** 3. 若成员存在, 返回其下标
*/
int IsItIn(PtrMember array, int size, int Mem_No)
{
    if (array == NULL) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (array[i].Per_No == Mem_No) {
            return i;
        }
    }
    return -1;
}

/*
** 操作: 给指定成员添加一个队伍, 队伍长度加1
** 参数:
** 1. 成员数组
** 2. 指定成员位置
** 3. 队伍编号
** 4. 队伍长度
*/
void InsertTeam(PtrMember array, int mem_pos, int team_No, int team_len)
{
    PtrTeam p = (PtrTeam) malloc(sizeof(Team));
    if (!p) {
        exit(EXIT_FAILURE);
    }
    p->team_Mem = team_len;
    p->team_No = team_No;
    p->next = array[mem_pos].team_list;
    array[mem_pos].team_list = p;
    array[mem_pos].team_Num++;
}

/*
** 操作: 判断是否是太帅而没有朋友, 判断完之后改为1
** 参数:
** 1. 成员数组
** 2. 数组大小
** 3. 待判断成员
** 返回值:
** 1. 若数组中没有该成员返回-1
** 2. 若该成员没有一个team人数超过1返回-2
** 3. 其他情况返回0
*/
int NoFriend(PtrMember array, int size, int Mem_No)
{
    int r = IsItIn(array, size, Mem_No);
    if (r == -1) {
        return -1;
    } else {
        if (array[r].IsntSearch == 0) {
            PtrTeam p = array[r].team_list;
            array[r].IsntSearch = 1;
            while (p) {
                if (p->team_Mem > 1) {
                    return 0;
                }
                p = p->next;
            }
            return -2;
        }
    }
    return 0;
}

/*
** 操作: 销毁成员表
** 参数:
** 1. 成员数组
** 2. 数组大小
*/
void DestroyArray(PtrMember array, int size)
{
    PtrTeam p;
    PtrTeam s;
    for (int i = 0; i < size; i++) {
        if (array[i].team_Num != 0) {
            p = array[i].team_list;
            while (p) {
                s = p;
                p = p->next;
                free(s);
            }
        }
    }
    free(array);
}