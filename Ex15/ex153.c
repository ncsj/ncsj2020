#include <stdio.h>

int main(){
    char  line[256];
    FILE  *fp;
    char  *s;
    int   flag = 1;
    
    fp = fopen("example.txt","rt");
    if(fp != NULL){
        while(flag == 1){
            s = fgets(line,256,fp);
            if(s == NULL){
                flag = 0;
            }
            else{
                printf("%s",line);
            }
        }
        fclose(fp);
    }
    
    return 0;
}
