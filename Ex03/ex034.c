#include <stdio.h>

typedef  struct _DATA{
    int  x;
    int  y;
}DATA;

int main(){
    DATA  array[10];
    int   i;
    DATA  *p;
    
    for(i=0;i<10;i++){
        array[i].x = 100 + i;
        array[i].y = 200 + i;
    }
    
    p = array;
    for(i=0;i<10;i++){
        printf("%d , %d\n",p->x,p->y);
        p++;
    }
    printf("------------\n");
    p = array;
    for(i=0;i<10;i++){
        printf("%d , %d\n",(p+i)->x,(p+i)->y);
    }
    return 0;
}
