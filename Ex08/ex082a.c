#include <stdio.h>
#include "ex08.h"

void scopy(char *s1,const char *s2){
    int  i=0;
    
    while(*(s2+i) != 0x00){
        *(s1+i) = *(s2+i);
        i++;
    }
    
    *(s1+i) = 0x00;
}

void  f(){
    printf("Hello!\n");
}

int plus(int x,int y){
    return x + y;
}

void set(DATA *p){
    p->x = 100;
    p->y = 23;
}

void print(DATA *p){
    printf("%d,%d\n",p->x,p->y);
}
