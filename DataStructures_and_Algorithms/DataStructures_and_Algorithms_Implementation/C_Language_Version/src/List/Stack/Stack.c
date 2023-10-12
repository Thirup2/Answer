#include "Stack.h"
#include <stdlib.h>
#include <ctype.h>

void ShowStack(PtrStack stack, FILE *out);
char GetChoice(FILE *in);
void Insert(PtrStack stack, FILE *in, FILE *out);
void Delete(PtrStack stack, FILE *in, FILE *out);
void DrawALine(FILE *out);

int main(void)
{
    FILE *in;
    FILE *out;
    if (STDIN) {
        in = stdin;
    } else {
        in = fopen("../input/Stack.input", "r");
        if (!in) {
            printf("Error: Faild to open input file.\n");
            exit(EXIT_FAILURE);
        }
    }
    if (STDOUT) {
        out = stdout;
    } else {
        out = fopen("../output/Stack.output", "w");
        if (!out) {
            printf("Error: Faild to open output file.\n");
            exit(EXIT_FAILURE);
        }
    }
    PtrStack stack = InitStack();
    ShowStack(stack, out);
    char ch;
    DrawALine(out);
    while (ch = GetChoice(in)) {
        if (ch == 'I') {
            Insert(stack, in, out);
        } else if (ch == 'D') {
            Delete(stack, in, out);
        } else if (ch == '\n') {
            fprintf(out, "\n");
            continue;
        } else {
            fprintf(out, "EXIT: Program about to exit!\n");
            break;
        }
        while (getc(in) != '\n');
    }
    fclose(in);
    DrawALine(out);
    ShowStack(stack, out);
    fprintf(out, "DESTROY: The Stack is about to be destroyed...\n");
    DestroyStack(stack);
    fprintf(out, "DESTROY: Destruction completed!\n");
    fclose(out);

    return 0;
}
void ShowStack(PtrStack stack, FILE *out)
{
    DrawALine(out);
    fprintf(out, "Testing stack:\n");
    fprintf(out, " >> Is it empty: %s\n", StackEmpty(stack) ? "Yes" : "No");
    fprintf(out, " >> Its Length: %d\n", Length(stack));
    fprintf(out, " >> Its top: ");
    ElemType top;
    Status sta = GetTop(stack, &top);
    if (sta == ISEMPTY) {
        fprintf(out, "NULL");
    } else {
        PrintElem(&top, out);
    }
    fprintf(out, "\n");
    fprintf(out, " >> Its Content: ");
    PrintStack(stack, out);
    fprintf(out, "\n");
    DrawALine(out);
}
char GetChoice(FILE *in)
{
    char ch;
    ch = toupper(getc(in));
    return ch;
}
void Insert(PtrStack stack, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    Status sta;
    ReadElem(elem, in);
    sta = Push(stack, elem);
    fprintf(out, "Push: ");
    if (sta == ISFULL) {
        fprintf(out, "Stack is full.\n");
    } else {
        fprintf(out, "Element ");
        PrintElem(elem, out);
        fprintf(out, " was successfully pushed.\n");
    }
    DestroyElem(elem);
}
void Delete(PtrStack stack, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    Status sta;
    sta = Pop(stack, elem);
    fprintf(out, "Pop: ");
    if (sta == ISEMPTY) {
        fprintf(out, "Stack is empty.\n");
    } else {
        fprintf(out, "The top element to be poped is ");
        PrintElem(elem, out);
        fprintf(out, ".\n");
    }
    DestroyElem(elem);
}
void DrawALine(FILE *out)
{
    for (int i = 0; i < 50; i++) {
        fputc('-', out);
    }
    fputc('\n', out);
}