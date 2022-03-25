#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n,times;
    int count=0;
    int guess;
    scanf("%d %d",&n,&times);
    if(n>=1&&n<=100&&times>3){
        while(scanf("%d",&guess)==1&&guess<=100){
            count++;
            if(guess<0){
                printf("Game Over\n");
                exit(EXIT_SUCCESS);
            }else if(guess>n){
                printf("Too big\n");
            }else if(guess<n){
                printf("Too small\n");
            }else if(guess==n){
                if(count==1){
                    printf("Bingo!\n");
                }else if(count<=3){
                    printf("Lucky You!\n");
                }else if(count<=times){
                    printf("Good Guess!\n");
                }else{
                    printf("Game Over\n");
                }
                exit(EXIT_SUCCESS);
            }
        }
    }

    return 0;
}