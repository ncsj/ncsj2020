#include <stdio.h>

int main(){
    char  s[129];
    char  fname[20];
    
    char  buff[129];
    int   i;
    
    FILE  *fp;
    char *p;
    int  rtc;
    int  loop;
    
    for(i=0;i<129;i++){
        buff[i] = 0x00;
        s[i] = 0x00;
    }
    
    printf("INPUT STRING >");
    scanf("%s",s);
    
    printf("%s\n",s);
    
    
    printf("FILE NAME : ");
    scanf("%s",fname);
    
    fp = fopen(fname,"w+t");
    if(fp != NULL){
        p = s;
        while(*p != 0x00){
            rtc = fputc(*p,fp);
            if(rtc == -1){
                printf("I/O ERROR!\n");
                break;
            }
            p++;
        }
        fclose(fp);
    }
    
    printf("THE END.\n");
    
    fp = fopen(fname,"rt");
    if(fp != NULL){
        loop = 1;
        i = 0;
        while(loop == 1){
            rtc = fgetc(fp);
            if(rtc > EOF){
                buff[i] = (char)rtc;
                i++;
            }
            else{
                loop = 0;
            }
        }
        fclose(fp);
        
        printf("buff : %s\n",buff);
    }
    else{
        printf("FILE OPEN ERROR!\n");
        printf("FILE : %s\n",fname);
    }
    
    return 0;
}
