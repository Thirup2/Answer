#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 5
typedef struct{
    char first[40];
    char last[40];
}names;
names staff[SIZE];
void set_name(names list[],int n);
void show_name(const names list[],int n);
int mycomp(const void * p1,const void * p2);
int main(void)
{
    set_name(staff,SIZE);
    show_name(staff,SIZE);
    qsort(staff,SIZE,sizeof(names),mycomp);
    printf("Sorted list:\n");
    show_name(staff,SIZE);
    return 0;
}
void set_name(names list[],int n)
{
    for(int i=0;i<n;i++){
        printf("Enter the No.%d stuff name:",i+1);
        scanf("%s %s",list[i].first,list[i].last);
    }
}
void show_name(const names list[],int n)
{
    for(int i=0;i<n;i++){
        printf("Stuff No.%d %10s.%-10s\n",i+1,list[i].first,list[i].last);
    }
}
int mycomp(const void *p1,const void *p2)
{
    const names*ps1=(const names*)p1;
    const names*ps2=(const names*)p2;
    int res=strcmp(ps1->last,ps2->last);
    if(res!=0){
        return res;
    }else{
        return strcmp(ps1->first,ps2->first);
    }
}