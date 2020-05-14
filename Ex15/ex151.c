#include <stdio.h>

int readText(){
    FILE  *fp;
    int  c;
    int  flag = 1;
    
    fp = fopen("example.txt","rt");
    if(fp != NULL){
        while(flag == 1){
            c = fgetc(fp);
            switch( c ){
                case -1:
                    flag = 0;
                    break;
                default:
                    printf("%c",(char)c);
                    break;
            }
        }
        fclose(fp);
        
        printf("\n");
    }
    else{
        printf("FILE OPEN ERROR : example.txt\n");
    }
    
    return 0;
}
