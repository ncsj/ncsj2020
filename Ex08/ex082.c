#include <stdio.h>
#include "ex08.h"

int main(){
    int  result;
    int  x;
    int  y;
    char  s1[128];
    char  s2[128];
    
    DATA data;
    
    f();
    
    x = 100;
    y = 23;
    result = plus(100,23);
    
    printf("%d + %d = %d\n",x,y,result);
    
    printf("----------\n");
    
    printf("S1 : ");
    scanf("%s",s1);
    
    scopy(s2,s1);
    
    printf("%s : %s\n",s1,s2);
    
    set(&data);
    print(&data);
    
    return 0;
}
