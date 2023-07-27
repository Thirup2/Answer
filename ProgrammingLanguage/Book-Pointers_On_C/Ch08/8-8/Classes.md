# 一. 主逻辑

1. 在棋盘上设置第一个棋子（从头开始放），然后更新禁区（即会与前面已经落子的棋子相冲突的区域）

2. 将第二个棋子放在禁区外的第一个有效位置……将第 n 个棋子放在禁区外的第一个有效位置

3. 若当前棋子无有效位可放，就移动上一个棋子至它对应的下一个有效位

4. 当最后一个棋子放下后，输出一组有效位组合

5. ~当第一个棋子走遍所有有效位之后结束查找~

   ~**优化**：当第一个棋子所在列数到棋盘最后一列的列数小于棋子个数时退出循环~
   
   **优化**：每个棋子的有效区域应该只能在棋子序对应的行数，如果超过就移动前一个棋子然后再找到其他组合，这种情况下每个棋子序都会在对应的行数，直到第一个棋子无有效区域时退出循环

**注意**：

- 后落子的棋子必须落在先落子的棋子之后，也就是说棋盘上当前位置最靠后的棋子的前面所有位置都是禁区
- 每个棋子的有效区域应该只能在棋子序对应的行数
- 禁区需要时刻更新，如落子之后，提子之后



# 二. 类及接口

## 1. 棋子类：Chess

### （1）类成员

| 类成员 | 定义                   |
| ------ | ---------------------- |
| `x`    | 落子的行数：`int` |
| `y`    | 落子的列数：`int` |



## 2. 棋盘类：ChessBoard

### （1）类成员

| 类成员        | 定义                               |
| ------------- | ---------------------------------- |
| `BoardSize`   | 棋盘的大小（正方形边长）：`int` |
| `ChessCount`  | 棋子的个数：`int`               |
| `PenaltyArea` | 禁区矩阵：`bool **`                |
| `Chesses`     | 棋子数组：`Chess *`                |



### （2）函数接口

|函数|操作|参数|返回|
|---|---|---|---|
|`CreateChessBoard`|创建一个棋盘及其内容并初始化|1. 棋盘的大小<br />2. 棋子的个数|指向棋盘的指针|
|`InitChessBoard`|初始化一个棋盘及其内容|1. 棋盘|void|
|`DestroyChessBoard`|销毁一个棋盘及其内容|1. 棋盘|void|
|`GetRightGroups`|获取并输出所有有效位组合(主逻辑)|1. 棋盘|符合的组合个数|
|`DownChess`|落子|1. 棋盘<br />2. 棋子序<br />3. 落子位置|void|
|`UpChess`|提子|1. 棋盘<br />2. 棋子序|void|
|`UpdatePenaltyArea`|更新禁区|1. 棋盘<br />2. 需要更新位置的棋子的当前位置|void|
|`GetNextPosition`|获取当前位置后第一个有效位置|1. 棋盘<br />2. 需要更新位置的棋子的当前位置|位置，若无有效位置返回NULL|
|`IsAllDown`|判断是否所有棋子都已落子|1. 棋盘|True or False|
|`OutRightGroup`|输出一个无冲组合|1. 棋盘|void|
|`IsItDown`|判断棋子是否已落子|1. 棋盘<br />2. 棋子序|True or False|