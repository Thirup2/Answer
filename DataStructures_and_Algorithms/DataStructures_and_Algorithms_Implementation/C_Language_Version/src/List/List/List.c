#include "List.h"
#include <ctype.h>
#include <stdlib.h>

void ShowList(PtrList list, FILE *out);
char GetChoice(FILE *in);
void Locate(PtrList list, FILE *in, FILE *out);
void Get(PtrList list, FILE *in, FILE *out);
void Insert(PtrList list, FILE *in, FILE *out);
void Delete(PtrList list, FILE *in, FILE *out);
void DrawALine(FILE *out);

int main(void)
{
    FILE *in;
    FILE *out;
    if (STDIN) {
        in = stdin;
    } else {
        in = fopen("../input/List.input", "r");
        if (!in) {
            printf("Error: Faild to open input file.\n");
            exit(EXIT_FAILURE);
        }
    }
    if (STDOUT) {
        out = stdout;
    } else {
        out = fopen("../output/List.output", "w");
        if (!out) {
            printf("Error: Faild to open output file.\n");
            exit(EXIT_FAILURE);
        }
    }
    PtrList list = InitList();
    ShowList(list, out);
    char ch;
    DrawALine(out);
    while (ch = GetChoice(in)) {
        if (ch == 'L') {
            Locate(list, in, out);
        } else if (ch == 'G') {
            Get(list, in, out);
        } else if (ch == 'I') {
            Insert(list, in, out);
        } else if (ch == 'D') {
            Delete(list, in, out);
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
    ShowList(list, out);
    fprintf(out, "DESTROY: The List is about to be destroyed...\n");
    DestroyList(list);
    fprintf(out, "DESTROY: Destruction completed!\n");
    fclose(out);

    return 0;
}
void ShowList(PtrList list, FILE *out)
{
    DrawALine(out);
    fprintf(out, "Testing list:\n");
    fprintf(out, " >> Is it empty: %s\n", Empty(list) ? "Yes" : "No");
    fprintf(out, " >> Its Length: %d\n", Length(list));
    fprintf(out, " >> Its Content: ");
    PrintList(list, out);
    fprintf(out, "\n");
    DrawALine(out);
}
char GetChoice(FILE *in)
{
    char ch;
    ch = toupper(getc(in));
    return ch;
}
void Locate(PtrList list, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    ReadElem(elem, in);
    int res = LocateElem(list, elem);
    fprintf(out, "Locate: Element ");
    PrintElem(elem, out);
    fprintf(out, " ");
    if (res) {
        fprintf(out, "is in the %d%s position in the list.\n", res,
                (res % 10 == 1 ? "st" : (res % 10 == 2 ? "nd" : (res % 10 == 3 ? "rd" : "th"))));
    } else {
        fprintf(out, "is not in the list.\n");
    }
    DestroyElem(elem);
}
void Get(PtrList list, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    int pos;
    Status sta;
    fscanf(in, "%d", &pos);
    sta = GetElem(list, pos, elem);
    fprintf(out, "Get: ");
    if (sta == ISEMPTY) {
        fprintf(out, "List is empty.\n");
    } else if (sta == WRONGPOS) {
        fprintf(out, "You entered a wrong position.\n");
    } else {
        fprintf(out, "The %d%s position in the list is element ", pos,
                (pos % 10 == 1 ? "st" : (pos % 10 == 2 ? "nd" : (pos % 10 == 3 ? "rd" : "th"))));
        PrintElem(elem, out);
        fprintf(out, ".\n");
    }
    DestroyElem(elem);
}
void Insert(PtrList list, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    int pos;
    Status sta;
    ReadElem(elem, in);
    fscanf(in, "%d", &pos);
    sta = ListInsert(list, pos, elem);
    fprintf(out, "Insert: ");
    if (sta == ISFULL) {
        fprintf(out, "List is full.\n");
    } else if (sta == WRONGPOS) {
        fprintf(out, "You entered a wrong position.\n");
    } else {
        fprintf(out, "Element ");
        PrintElem(elem, out);
        fprintf(out, " was successfully inserted at the %d%s position in the list.\n", pos,
                (pos % 10 == 1 ? "st" : (pos % 10 == 2 ? "nd" : (pos % 10 == 3 ? "rd" : "th"))));
    }
    DestroyElem(elem);
}
void Delete(PtrList list, FILE *in, FILE *out)
{
    PtrElem elem = CreateElem();
    int pos;
    Status sta;
    fscanf(in, "%d", &pos);
    sta = ListDelete(list, pos, elem);
    fprintf(out, "Delete: ");
    if (sta == ISEMPTY) {
        fprintf(out, "List is empty.\n");
    } else if (sta == WRONGPOS) {
        fprintf(out, "You entered a wrong position.\n");
    } else {
        fprintf(out, "The %d%s element to be removed is ", pos,
                (pos % 10 == 1 ? "st" : (pos % 10 == 2 ? "nd" : (pos % 10 == 3 ? "rd" : "th"))));
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