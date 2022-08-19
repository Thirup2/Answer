#include <string.h>
int substr(char dst[],char src[],int start,int len)
{
    int count=0;
    int src_len=strlen(src);
    if(start>=src_len||start<0||len<0){
        dst[0]='\0';
        return 0;
    }
    for(int i=start;count<len;count++,i++){
        if(src[i]=='\0'){
            dst[count]='\0';
            return count;
        }else{
            dst[count]=src[i];
        }
    }
    dst[len]='\0';
    return count;
}