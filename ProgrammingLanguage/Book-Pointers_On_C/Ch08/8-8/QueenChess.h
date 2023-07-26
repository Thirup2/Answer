/*
   棋盘类头文件
   请先查看类文档‘Classes.md’
*/
#ifndef _QUEENCHESS_H_
#define _QUEENCHESS_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 类型定义 */
struct chess
{
    int x;          // 棋子的行数
    int y;          // 棋子的列数
};
typedef struct chess Chess;
typedef Chess *PtrChess;

struct chessboard
{
    int BoardSize;      // 棋盘的大小
    int ChessCount;     // 棋子的个数
    bool **PenaltyArea; // 禁区
    PtrChess Chesses;   // 棋子数组
};
typedef struct chessboard ChessBoard;
typedef ChessBoard *PtrChessBoard;

/* 函数接口 */
PtrChessBoard CreateChessBoard(int size, int cnt);
void InitChessBoard(PtrChessBoard board);
void DestroyChessBoard(PtrChessBoard board);
int GetRightGoups(PtrChessBoard board);
void DownChess(PtrChessBoard board, int chessnum, PtrChess position);
void UpChess(PtrChessBoard board, int chessnum);
void UpdatePenaltyArea(PtrChessBoard board, PtrChess now);
PtrChess GetNextPosition(PtrChessBoard board, PtrChess now);
bool IsAllDown(PtrChessBoard board);
void OutRightGroup(PtrChessBoard board);
bool IsItDown(PtrChessBoard board, int chessnum);

/* 接口实现 */
PtrChessBoard CreateChessBoard(int size, int cnt)
{
    // 首先是棋盘结构的内存
    PtrChessBoard board = (PtrChessBoard) malloc(sizeof(ChessBoard));
    if (!board) {
        exit(EXIT_FAILURE);
    }
    board->BoardSize = size;
    board->ChessCount = cnt;
    // 禁区的内存分配
    // 外层数组分配
    board->PenaltyArea = (bool **) malloc(size * sizeof(bool *));
    if (!board->PenaltyArea) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        // 内存数组分配
        board->PenaltyArea[i] = (bool *) malloc(size * sizeof(bool));
        if (!board->PenaltyArea[i]) {
            exit(EXIT_FAILURE);
        }
    }
    // 棋子的内存分配
    board->Chesses = (PtrChess) malloc(cnt * sizeof(Chess));
    if (!board->Chesses) {
        exit(EXIT_FAILURE);
    }
    // 初始化
    InitChessBoard(board);

    return board;
}

void InitChessBoard(PtrChessBoard board)
{
    // 禁区首先设置为全部有效
    for (int i = 0; i < board->BoardSize; i++) {
        for (int j = 0; j < board->BoardSize; j++) {
            board->PenaltyArea[i][j] = true;
        }
    }
    // 每个棋子设置为未落子状态
    for (int i = 0; i < board->ChessCount; i++) {
        board->Chesses[i].x = -1;
        board->Chesses[i].y = -1;
    }
}

void DestroyChessBoard(PtrChessBoard board)
{
    // 释放禁区的内层数组
    for (int i = 0; i < board->BoardSize; i++) {
        free(board->PenaltyArea[i]);
    }
    // 释放外层数组
    free(board->PenaltyArea);
    // 释放棋子数组
    free(board->Chesses);
    // 释放棋盘结构
    free(board);
}

int GetRightGoups(PtrChessBoard board)          // 主逻辑函数
{
    int i = 0;      // 当前棋子序（未落子棋子中的第一个的位序）
    PtrChess position = (PtrChess) malloc(sizeof(Chess));       // 用于返回有效位置
    if (!position) {                    // 此处分配空间的原因不是因为需要分配，主要是为了和接下来遇到的第一个free配合
        exit(EXIT_FAILURE);
    }
    PtrChess now = (PtrChess) malloc(sizeof(Chess));            // 返回当前棋子的已占位置，用于传入函数获取该位置之后的位置，保证不会进入死循环
    if (!now) {                         // 此处分配空间是必要的，同时需要在本函数最后进行释放
        exit(EXIT_FAILURE);
    }
    int cnt = 0;                        // 保存无冲组合个数，并用于返回
    while (i >= 0) {                    // 此处之所以条件是这样，请详细阅读了函数体之后再进行考虑
        // 获取当前棋子的位置状态
        // 当前棋子有两种可能：
        // 1. 是按照顺序往后的一个未落子的棋子
        // 2. 是因为没有有效区域而退回到的前一个棋子
        now->x = board->Chesses[i].x;
        now->y = board->Chesses[i].y;

        // 对于上述的第一种情况来说，是不需要提子的，但提子不影响程序进行
        // 对于第二种情况，需要先提子再获取位置信息
        // 所以此处进行提子操作
        UpChess(board, i);

        // 此处的free的目的是因为下面的GetNextPosition函数会为position分配空间而不会进行释放，所以在此处进行释放
        // 当首次遇到该free的时候，还没有position被分配空间，所以在前面为position分配了空间，否则会引发错误
        // 而后续遇到该free的时候，position都是已经被GetNextPosition函数分配空间之后的
        free(position);

        // 获取位置
        // 最后一次获取位置之后，将不会进行free，所以在本函数末尾还需要进行释放
        position = GetNextPosition(board, now);

        // 获取的位置有三种情况，前两种情况都需要退回到前一个棋子
        // 1. 无有效区域
        if (position->x == -1 || position->y == -1) {
            i--;
            continue;
        }
        // 2. 当前棋子的棋子序与位置的行数不对应
        if (position->x > i) {
            i--;
            continue;
        }
        // 3. 正常情况，落子
        DownChess(board, i, position);

        // 当所有棋子都已落子时，当前组合一定是无冲组合，即输出
        if (IsAllDown(board)) {
            OutRightGroup(board);
            cnt++;
            // 此处并未递增i，所以函数在输出一个组合并不会退出
            // 因为需要输出所有组合之后才能退出
            // 而输出完所有组合之后，一定是退回到第一个棋子之后，然后第一个棋子的第一个有效位置的行数与棋子序不对应才导致的退出，即第一个棋子的第一个有效位置已经在第二行去了
            // 所以循环的退出条件是 i < 0 ，而不是 i > board->ChessCount
        } else {
            // 当还有棋子未落子时，移动到下一个棋子，尝试落子
            i++;
        }
    }

    // 对前面分配的空间进行释放
    free(position);
    free(now);

    return cnt;
}

void DownChess(PtrChessBoard board, int chessnum, PtrChess position)
{
    // 在主逻辑函数中，position的位置由GetNextPosition进行保证它的正确性
    // 所以position一定是在棋盘上的，且是在有效区域的，所以直接进行落子即可
    board->Chesses[chessnum].x = position->x;
    board->Chesses[chessnum].y = position->y;
}

void UpChess(PtrChessBoard board, int chessnum)
{
    // 程序以(-1, -1)表示棋盘外
    board->Chesses[chessnum].x = -1;
    board->Chesses[chessnum].y = -1;
}

void UpdatePenaltyArea(PtrChessBoard board, PtrChess now)
{
    // 严格来说，每个棋子的禁区还应包括除了棋子序对应的棋盘行数之外的所有区域，但在该函数内不进行此概念的实现，在主逻辑函数可以看到有对该点的处理
    // 所以接下来的禁区设置是除了上述情况之外的其他情况

    // 由于棋子一直在变动，所以在更新禁区之前先初始化禁区
    for (int x = 0; x < board->BoardSize; x++) {
        for (int y = 0; y < board->BoardSize; y++) {
            board->PenaltyArea[x][y] = true;
        }
    }

    // 接下来将now之前的位置设置为禁区，设置一行即可，因为棋子完全按照顺序落子，其前面行数的禁区会在后续进行设置
    for (int x = now->x, y = 0; y <= now->y; y++) {
        board->PenaltyArea[x][y] = false;
    }

    // 遍历所有已落子的棋子，设置禁区
    for (int i = 0; IsItDown(board, i); i++) {
        // 同一行数的位置设置为禁区
        for (int x = board->Chesses[i].x, n = 0; n < board->BoardSize; n++) {
            board->PenaltyArea[x][n] = false;
        }
        // 同一列数的位置设置为禁区
        for (int y = board->Chesses[i].y, n = 0; n < board->BoardSize; n++) {
            board->PenaltyArea[n][y] = false;
        }
        // 同一正斜线的位置设置为禁区
        for (int x = board->Chesses[i].x, y = board->Chesses[i].y; x < board->BoardSize && y < board->BoardSize; x++, y++) {
            board->PenaltyArea[x][y] = false;
        }
        for (int x = board->Chesses[i].x, y = board->Chesses[i].y; x >= 0 && y >= 0; x--, y--) {
            board->PenaltyArea[x][y] = false;
        }
        // 统一负斜线的位置设置为禁区
        for (int x = board->Chesses[i].x, y = board->Chesses[i].y; x < board->BoardSize && y >= 0; x++, y--) {
            board->PenaltyArea[x][y] = false;
        }
        for (int x = board->Chesses[i].x, y = board->Chesses[i].y; x >= 0 && y < board->BoardSize; x--, y++) {
            board->PenaltyArea[x][y] = false;
        }
    }
}

PtrChess GetNextPosition(PtrChessBoard board, PtrChess now)
{
    PtrChess position;
    // 为position分配空间，在主逻辑函数中进行释放
    position = (PtrChess) malloc(sizeof(Chess));
    if (!position) {
        exit(EXIT_FAILURE);
    }
    // 初始化position
    position->x = -1;
    position->y = -1;
    // 更新禁区
    UpdatePenaltyArea(board, now);
    // 查找禁区中第一个有效位置
    for (int x = 0; x < board->BoardSize; x++) {
        for (int y = 0; y < board->BoardSize; y++) {
            // 若找到则更新position并返回
            if (board->PenaltyArea[x][y]) {
                position->x = x;
                position->y = y;
                return position;
            }
        }
    }
    // 若为找到直接返回(-1, -1)
    return position;
}

bool IsAllDown(PtrChessBoard board)
{
    // 判断是否所有棋子都已落子
    // 棋子不会产生越界错误，由主逻辑函数进行确保
    for (int i = 0; i < board->ChessCount; i++) {
        if (board->Chesses[i].x == -1 || board->Chesses[i].y == -1) {
            return false;
        }
    }
    return true;
}

void OutRightGroup(PtrChessBoard board)
{
    // 输出一个无冲组合
    // 组合是否无冲由主逻辑函数进行确保
    for (int i = 0; i < board->ChessCount; i++) {
        printf("(%d, %d) ", board->Chesses[i].x + 1, board->Chesses[i].y + 1);
    }
    printf("\n");
}

bool IsItDown(PtrChessBoard board, int chessnum)
{
    // 判断某个棋子是否已落子
    if (board->Chesses[chessnum].x == -1 || board->Chesses[chessnum].y == -1) {
        return false;
    }
    return true;
}

#endif