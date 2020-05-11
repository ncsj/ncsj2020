#include <stdio.h>

#define ON      1
#define OFF     0

#define PLUS    1
#define MINUS   2
#define EXIT    9

#define KOZOTAI     struct

int menu(){
    int  rtc;
    
    printf("1:PLUS 2:MINUS ... 9:EXIT\n");
    printf("SELECT NUMBER >");
    scanf("%d",&rtc);
    
    return rtc;
}

void plus(){
    int  x,y,z;
    
    printf("x : ");
    scanf("%d",&x);
    
    printf("y : ");
    scanf("%d",&y);
    
    z = x + y;
    printf("%d + %d = %d\n",x,y,z);
}

void minus(){
    int  x,y,z;
    
    printf("x : ");
    scanf("%d",&x);
    
    printf("y : ");
    scanf("%d",&y);
    
    z = x - y;
    printf("%d - %d = %d\n",x,y,z);
}

KOZOTAI JOHO{
    int     i;
    int     ro;
    int     ha;
};

int main(){
    int  loop;
    int  count = 0;
    int  n;
    
    KOZOTAI JOHO joho;
    
    joho.i  = 1;
    joho.ro = 2;
    joho.ha = 3;
    
    printf("%d,%d,%d\n",joho.i,joho.ro,joho.ha);
    
    loop = ON;
    while(loop == ON){
        n = menu();
        switch( n ){
            case PLUS:
                plus();
                break;
            case MINUS:
                minus();
                break;
            case EXIT:
                loop = OFF;
                break;
            default:
                break;
        }
        count++;
    }
    
    printf("COUNT : %d\n",count);
    
    return 0;
}
