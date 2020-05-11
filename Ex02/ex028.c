#include <stdio.h>

int mod(int n){
    int m;
    
    m = n % 2;
    
    return m;
}

int main(){
    int  x;
    int  m;
    
    printf("INPUT x : ");
    scanf("%d",&x);
    
    m = mod(x);
    if(m == 0){
        printf("x is even.\n");
    }
    else if(m == 1){
        printf("x is odd.\n");
    }

    return 0;
}
