/* 棋盘类头文件 */
#ifndef _QUEENCHESS_H_
#define _QUEENCHESS_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

/* 类型定义 */
struct chess
{
    int x;
    int y;
};
typedef struct chess Chess;
typedef Chess *PtrChess;

struct chessboard
{
    int BoardSize;
    int ChessCount;
    bool **PenaltyArea;
    PtrChess Chesses;
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
    PtrChessBoard board = (PtrChessBoard) malloc(sizeof(ChessBoard));
    if (!board) {
        exit(EXIT_FAILURE);
    }
    board->BoardSize = size;
    board->ChessCount = cnt;
    board->PenaltyArea = (bool **) malloc(size * sizeof(bool *));
    if (!board->PenaltyArea) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        board->PenaltyArea[i] = (bool *) malloc(size * sizeof(bool));
        if (!board->PenaltyArea[i]) {
            exit(EXIT_FAILURE);
        }
    }
    board->Chesses = (PtrChess) malloc(cnt * sizeof(Chess));
    if (!board->Chesses) {
        exit(EXIT_FAILURE);
    }
    InitChessBoard(board);
    return board;
}

void InitChessBoard(PtrChessBoard board)
{
    for (int i = 0; i < board->BoardSize; i++) {
        for (int j = 0; j < board->BoardSize; j++) {
            board->PenaltyArea[i][j] = true;
        }
    }
    for (int i = 0; i < board->ChessCount; i++) {
        board->Chesses[i].x = -1;
        board->Chesses[i].y = -1;
    }
}

void DestroyChessBoard(PtrChessBoard board)
{
    for (int i = 0; i < board->BoardSize; i++) {
        free(board->PenaltyArea[i]);
    }
    free(board->PenaltyArea);
    free(board->Chesses);
    free(board);
}

int GetRightGoups(PtrChessBoard board)
{
    int i = 0;
    PtrChess position = (PtrChess) malloc(sizeof(Chess));
    if (!position) {
        exit(EXIT_FAILURE);
    }
    PtrChess now = (PtrChess) malloc(sizeof(Chess));
    if (!now) {
        exit(EXIT_FAILURE);
    }
    int cnt = 0;
    while (i >= 0) {
        now->x = board->Chesses[i].x;
        now->y = board->Chesses[i].y;
        UpChess(board, i);
        free(position);
        position = GetNextPosition(board, now);
        if (!position) {
            i--;
            continue;
        }
        if (position->x > i) {
            i--;
            continue;
        }
        DownChess(board, i, position);
        if (IsAllDown(board)) {
            OutRightGroup(board);
            cnt++;
        } else {
            i++;
        }
    }

    free(position);
    free(now);

    return cnt;
}

void DownChess(PtrChessBoard board, int chessnum, PtrChess position)
{
    board->Chesses[chessnum].x = position->x;
    board->Chesses[chessnum].y = position->y;
}

void UpChess(PtrChessBoard board, int chessnum)
{
    board->Chesses[chessnum].x = -1;
    board->Chesses[chessnum].y = -1;
}

void UpdatePenaltyArea(PtrChessBoard board, PtrChess now)
{
    for (int x = 0; x < board->BoardSize; x++) {
        for (int y = 0; y < board->BoardSize; y++) {
            board->PenaltyArea[x][y] = true;
        }
    }
    int i = 0;
    for (; i < now->x; i++) {
        for (int j = 0; j < board->BoardSize; j++) {
            board->PenaltyArea[i][j] = false;
        }
    }
    for (int j = 0; j <= now->y; j++) {
        board->PenaltyArea[i][j] = false;
    }
    for (i = 0; IsItDown(board, i); i++) {
        for (int x = board->Chesses[i].x, n = 0; n < board->BoardSize; n++) {
            board->PenaltyArea[x][n] = false;
        }
        for (int y = board->Chesses[i].y, n = 0; n < board->BoardSize; n++) {
            board->PenaltyArea[n][y] = false;
        }
        for (int x = board->Chesses[i].x, y = board->Chesses[i].y; x < board->BoardSize && y < board->BoardSize; x++, y++) {
            board->PenaltyArea[x][y] = false;
        }
        for (int x = board->Chesses[i].x, y = board->Chesses[i].y; x >= 0 && y >= 0; x--, y--) {
            board->PenaltyArea[x][y] = false;
        }
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
    position = (PtrChess) malloc(sizeof(Chess));
    if (!position) {
        exit(EXIT_FAILURE);
    }
    position->x = -1;
    position->y = -1;
    UpdatePenaltyArea(board, now);
    for (int x = 0; x < board->BoardSize; x++) {
        for (int y = 0; y < board->BoardSize; y++) {
            if (board->PenaltyArea[x][y]) {
                position->x = x;
                position->y = y;
                return position;
            }
        }
    }
    return NULL;
}

bool IsAllDown(PtrChessBoard board)
{
    for (int i = 0; i < board->ChessCount; i++) {
        if (board->Chesses[i].x == -1 || board->Chesses[i].y == -1) {
            return false;
        }
    }
    return true;
}

void OutRightGroup(PtrChessBoard board)
{
    for (int i = 0; i < board->ChessCount; i++) {
        printf("(%d, %d) ", board->Chesses[i].x + 1, board->Chesses[i].y + 1);
    }
    printf("\n");
}

bool IsItDown(PtrChessBoard board, int chessnum)
{
    if (board->Chesses[chessnum].x == -1 || board->Chesses[chessnum].y == -1) {
        return false;
    }
    return true;
}

#endif