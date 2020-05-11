#include <stdio.h>
#include <stdlib.h>

typedef struct _DATA{
    int  x;
    int  y;
}DATA;

int main(){
    DATA  *p;
    int  i;
    
    p = (DATA *)malloc(sizeof(DATA)*10);
    
    for(i=0;i<10;i++){
        (p+i)->x = 100 + i;
        (p+i)->y = 200 + i;
    }
    
    for(i=0;i<10;i++){
        printf("%d,%d\n",(p+i)->x,(p+i)->y);
    }
    
    free(p);
    return 0;
}
