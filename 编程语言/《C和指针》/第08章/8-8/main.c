#include "QueenChess.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("请按照格式输入参数：\n");
        printf("参数1：要创建的棋盘边长大小\n");
        printf("参数2：需要的皇后棋子个数：\n");
        return -1;
    }
    size_t size = atoi(argv[1]);
    size_t cnt = atoi(argv[2]);
    if (size < cnt) {
        printf("该大小棋盘下无法无冲突摆放%lu个棋子!\n", cnt);
        return -1;
    }
    PtrChessBoard board;
    int num;
    board = CreateChessBoard(size, cnt);
    num = GetRightGoups(board);
    if (num == 0) {
        printf("没有无冲组合!\n");
    }
    DestroyChessBoard(board);

    return 0;
}