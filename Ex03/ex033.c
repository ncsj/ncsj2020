#include <stdio.h>

typedef  struct DATA{
    int  x;
    int  y;
}Data;

int main(){
    Data  data;
    Data  *p;
    
    data.x = 100;
    data.y = 200;
    
    printf("%d , %d\n",data.x,data.y);
    
    p = &data;
    p->x = 0;
    p->y = 0;
    
    printf("%d , %d\n",p->x,p->y);
    
    return 0;
}
