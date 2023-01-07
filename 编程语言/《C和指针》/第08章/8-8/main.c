#include "QueenChess.h"

int main(void)
{
    int size = 8;
    int cnt = 8;
    PtrChessBoard board;
    int num;
    board = CreateChessBoard(size, cnt);
    num = GetRightGoups(board);
    if (num == 0) {
        printf("没有无冲组合!\n");
    } else {
        printf("一共有%d种组合\n", num);
    }
    DestroyChessBoard(board);

    return 0;
}