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
    size_t x;
    size_t y;
};
typedef struct chess Chess;
typedef Chess *PtrChess;

struct chessboard
{
    size_t BoardSize;
    size_t ChessCount;
    bool **PenaltyArea;
    PtrChess Chesses;
};
typedef struct chessboard ChessBoard;
typedef ChessBoard *PtrChessBoard;

/* 函数接口 */
PtrChessBoard CreateChessBoard(size_t size, size_t cnt);
void InitChessBoard(PtrChessBoard board);
void DestroyChessBoard(PtrChessBoard board);
int GetRightGoups(PtrChessBoard board);
void DownChess(PtrChessBoard board, size_t chessnum, PtrChess position);
void UpChess(PtrChessBoard board, size_t chessnum);
void UpdatePenaltyArea(PtrChessBoard board);
PtrChess GetNextPosition(PtrChessBoard board, int model);

/* 接口实现 */
PtrChessBoard CreateChessBoard(size_t size, size_t cnt)
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
            board->PenaltyArea[i][j] = false;
        }
    }
    for (int i = 0; i < board->ChessCount; i++) {
        board->Chesses[i].x = 0;
        board->Chesses[i].y = 0;
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
    size_t i;
    PtrChess position;
    int model;
    for (i = 0; i < board->ChessCount; i++) {
    }
}
void DownChess(PtrChessBoard board, size_t chessnum, PtrChess position);
void UpChess(PtrChessBoard board, size_t chessnum);
void UpdatePenaltyArea(PtrChessBoard board);
PtrChess GetNextPosition(PtrChessBoard board, int model);

#endif