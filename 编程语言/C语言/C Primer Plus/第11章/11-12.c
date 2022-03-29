#include <stdio.h>
#include <ctype.h>
#define SIZE 256

int check_words(char* input);
int check_upper(char* input);
int check_lower(char* input);
int check_punct(char* input);
int check_digit(char* input);

int main(void)
{
    char input[SIZE];
    int i=0;
    while((input[i++]=getchar())!=EOF){
        if(i>=SIZE){
            printf("Over flowed.\n");
            break;
        }
    }
    printf("Hello you input complete.\nNow let's counting.\n");
    printf("Input words %d.\n",check_words(input));
    printf("Input upper char %d.\n",check_upper(input));
    printf("Input lower char %d.\n",check_lower(input));
    printf("Input punct char %d.\n",check_punct(input));
    printf("input digital %d.\n",check_digit(input));

    return 0;
}

int check_words(char* input)
{
    int count =0;
    int start =0;
    while(*input!=EOF){
        if(isalpha(*input)==0&&start==0){
            input++;
        }else if(isalpha(*input)==0&&start==1){
            input++;
            count++;
            start=0;
        }else if(isalpha(*input)!=0){
            input++;
            start=1;
        }
    }
    if(start==1){
        count++;
    }
    return count;
}

int check_upper(char* input)
{
    int count=0;
    while(*input!=EOF){
        if(isupper(*input++)!=0){
            count++;
        }
    }
    return count;
}

int check_lower(char* input)
{
    int count=0;
    while(*input!=EOF){
        if(islower(*input++)!=0){
            count++;
        }
    }
    return count;
}

int check_punct(char* input)
{
    int count=0;
    while(*input!=EOF){
        if(ispunct(*input++)!=0){
            count++;
        }
    }
    return count;
}

int check_digit(char* input)
{
    int count=0;
    while(*input!=EOF){
        if(isdigit(*input++)!=0){
            count++;
        }
    }
    return count;
}