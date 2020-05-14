#include <stdio.h>

int readText( void );

int main(){
    FILE  *fp;
    int  i;
    
    const char text[] = "This is a pen.\nThis is an apple.\nTo be,or not not be.That is question.";
    
    fp = fopen("example.txt","wt");
    if(fp != NULL){
        i = 0;
        while(text[i] != 0x00){
            fputc(text[i],fp);
            printf("%c",text[i]);
            i++;
        }
        
        fclose(fp);
        
        printf("\n");
    }
    else{
        printf("FILE OPEN ERROR : example.txt\n");
    }
    
    printf("----- READ TEXT -----\n");
    
    readText();
    
    return 0;
}
