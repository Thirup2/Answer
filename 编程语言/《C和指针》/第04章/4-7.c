void deblank(char string[])
{
    int PreIsBlank=0;
    int i=0;
    while(string[i]!='\0'){
        if(string[i]==' '){
            if(PreIsBlank==0){
                PreIsBlank=1;
            }else{
                int j=i;
                while(string[j]!='\0'){
                    string[j]=string[j+1];
                    j++;
                }
            }
        }else{
            PreIsBlank=0;
        }
        i++;
    }
}