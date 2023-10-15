#include "Queue.h"
#include "stdlib.h"
#include "ctype.h"

void ShowQueue(PtrQueue queue, FILE *out);
char GetChoice(FILE *in);
void Insert(PtrQueue queue, FILE *in, FILE *out);
void Delete(PtrQueue queue, FILE *in, FILE *out);
void DrawALine(FILE *out);

int main(void)
{
    FILE *in;
    FILE *out;
    if (STDIN) {
        in = stdin;
    } else {
        in = fopen("../input/Queue.input", "r");
        if (!in) {
            printf("Error: Faild to open input file.\n");
            exit(EXIT_FAILURE);
        }
    }
    if (STDOUT) {
        out = stdout;
    } else {
        out = fopen("../output/Queue.output", "w");
        if (!out) {
            printf("Error: Faild to open output file.\n");
            exit(EXIT_FAILURE);
        }
    }
    PtrQueue queue = InitQueue();
    ShowQueue(queue, out);
    char ch;
    DrawALine(out);
    while (ch = GetChoice(in)) {
        if (ch == 'I') {
            Insert(queue, in, out);
        } else if (ch == 'D') {
            Delete(queue, in, out);
        } else if (ch == '\n') {
            fprintf(out, "\n");
            continue;
        } else if (ch == '#') {   // 注释符
        } else {
            fprintf(out, "EXIT: Program about to exit!\n");
            break;
        }
        while (getc(in) != '\n');
    }
    fclose(in);
    DrawALine(out);
    ShowQueue(queue, out);
    fprintf(out, "DESTROY: The Queue is about to be destroyed...\n");
    DestroyQueue(queue);
    fprintf(out, "DESTROY: Destruction completed!\n");
    fclose(out);
}
void ShowQueue(PtrQueue queue, FILE *out)
{
    DrawALine(out);
    fprintf(out, "Testing queue:\n");
    fprintf(out, " >> Is it empty: %s\n", QueueEmpty(queue) ? "Yes" : "No");
    fprintf(out, " >> Is it full: %s\n", QueueFull(queue) ? "Yes" : "No");
    fprintf(out, " >> Its Length: %d\n", Length(queue));
    fprintf(out, " >> Its Head: ");
    ElemType head;
    Status sta = GetHead(queue, &head);
    if (sta == ISEMPTY) {
        fprintf(out, "NULL");
    } else {
        PrintElem(&head, out);
    }
    fprintf(out, "\n");
    fprintf(out, " >> Its Content: ");
    PrintQueue(queue, out);
    fprintf(out, "\n");
    DrawALine(out);
}
char GetChoice(FILE *in)
{
    char ch = toupper(getc(in));
    return ch;
}
void Insert(PtrQueue queue, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    Status sta;
    ReadElem(elem, in);
    sta = EnQueue(queue, elem);
    fprintf(out, "Enqueue: ");
    if (sta == ISFULL) {
        fprintf(out, "Queue is full.\n");
    } else {
        fprintf(out, "Element ");
        PrintElem(elem, out);
        fprintf(out, " was successfully enqueued.\n");
    }
    DestroyElem(elem);
}
void Delete(PtrQueue queue, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    Status sta;
    sta = DeQueue(queue, elem);
    fprintf(out, "Dequeue: ");
    if (sta == ISEMPTY) {
        fprintf(out, "Queue is empty.\n");
    } else {
        fprintf(out, "The head element to be dequeued is ");
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