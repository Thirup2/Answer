#include "Matrix.h"
#include <ctype.h>
#include <stdlib.h>

char GetChoice(FILE *in);
void DrawALine(FILE *out);
void Update(PtrMatrix matrix, FILE *in, FILE *out);
void Get(PtrMatrix matrix, FILE *in, FILE *out);

int main(void)
{
    // 打开文件
    FILE *in;
    FILE *out;
    if (STDIN) {
        in = stdin;
    } else {
        in = fopen("../input/Matrix/TriDiaMatrix.input", "r");
        if (!in) {
            printf("Error: Faild to open input file.\n");
            exit(EXIT_FAILURE);
        }
    }
    if (STDOUT) {
        out = stdout;
    } else {
        out = fopen("../output/Matrix.output", "w");
        if (!out) {
            printf("Error: Faild to open output file.\n");
            exit(EXIT_FAILURE);
        }
    }

    // 读取矩阵阶数
    int order;
    fscanf(in, "%d", &order);
    while (getc(in) != '\n');

    // 获取矩阵内容并打印
    PtrMatrix matrix = InitMatrix(order);
    if (!matrix) {
        printf("Error: Faild to create matrix.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(out, "Read: Start reading matrix...\n");
    if (!ReadMatrix(matrix, in)) {
        printf("Error: Faild to read matrix.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(out, "Read: End of reading matrix. Its content follows:\n");
    PrintMatrix(matrix, out);
    DrawALine(out);
    while (getc(in) != '\n');

    // 测试开始
    char ch;
    while (ch = GetChoice(in)) {
        if (ch == 'U') {
            Update(matrix, in, out);
        } else if (ch == 'G') {
            Get(matrix, in, out);
        } else if (ch == '#') {     // 注释符
        } else if (ch == '\n') {
            fprintf(out, "\n");
            continue;
        } else {
            fprintf(out, "EXIT: Program about to exit!\n");
            break;
        }
        while (getc(in) != '\n');
    }

    // 结束处理
    fclose(in);
    DrawALine(out);
    fprintf(out, "EXIT: Matrix's content at now:\n");
    PrintMatrix(matrix, out);
    DrawALine(out);
    fprintf(out, "DESTROY: The Matrix is about to be destroyed...\n");
    DestroyMatrix(matrix);
    fprintf(out, "Destroy: Destruction completed!\n");
    fclose(out);

    return 0;
}
char GetChoice(FILE *in)
{
    return toupper(getc(in));
}
void DrawALine(FILE *out)
{
    for (int i = 0; i < 50; i++) {
        fputc('-', out);
    }
    fputc('\n', out);
}
void Update(PtrMatrix matrix, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    int i, j;
    fscanf(in, "%d, %d", &i, &j);
    ReadElem(elem, in);
    Status sta = UpdateElem(matrix, i, j, elem);
    fprintf(out, "Update: ");
    if (sta == WRONGPOS) {
        fprintf(out, "You have input a wrong position.\n");
    } else {
        fprintf(out, "The element at (%d, %d) was successfully updated by ", i, j);
        PrintElem(elem, out);
        fprintf(out, "\n");
    }
    DestroyElem(elem);
}
void Get(PtrMatrix matrix, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    int i, j;
    fscanf(in, "%d, %d", &i, &j);
    Status sta = GetElem(matrix, i, j, elem);
    fprintf(out, "Get: ");
    if (sta == WRONGPOS) {
        fprintf(out, "You have input a wrong position.\n");
    } else {
        fprintf(out, "The element at (%d, %d) is ", i, j);
        PrintElem(elem, out);
        fprintf(out, "\n");
    }
    DestroyElem(elem);
}