#include <stdio.h>

struct DATA{
    int  x;
    int  y;
};

void printData(struct DATA *p){
    printf("%d,%d\n",p->x,p->y);
}

int main(){
    struct DATA  data;
    struct DATA *p;
    
    data.x = 100;
    data.y = 200;
    
    printf("%d,%d\n",data.x,data.y);
    
    p = &data;
    
    p->x = 0;
    p->y = 0;
    
    printf("%d,%d\n",data.x,data.y);
    printData( p );
    printData(&data);
    
    return 0;
}
