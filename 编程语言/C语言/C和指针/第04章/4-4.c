void copy_n(char dst[],char src[],int n)
{
    int logo=1;
    for(int i=0;i<n;i++){
        if(src[i]!='\0'&&logo==1){
            dst[i]=src[i];
            logo==1;
        }
        if(src[i]=='\0'||logo==0){
            dst[i]='\0';
            logo==0;
        }
    }
}