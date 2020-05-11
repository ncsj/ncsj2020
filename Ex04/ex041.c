#include <stdio.h>

/*
 共用体 : union
 */
union DATA{
    short  x;
    char   s[2];
};

int main(){
    union DATA data;
    
    // data.x = 0x0102;
    data.x = 'A';
    
    printf("data.x : %d - %04x\n",data.x,data.x);
    
    printf("----------\n");
    
    printf("data.s : [%d][%d]\n",data.s[0],data.s[1]);
    printf("data.s : [%02x][%02x]\n",data.s[0],data.s[1]);

    return 0;
}
