#include <stdio.h>

int main(){
    int  x;
    int  m;
    
    printf("INPUT x : ");
    scanf("%d",&x);
    
    m = x % 2;
    if(m == 0){
        printf("x is even.\n");
    }
    else if(m == 1){
        printf("x is odd.\n");
    }
    
    return 0;
}
