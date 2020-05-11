#include <stdio.h>

int  selNumber(int n,int col){
    int  rtc = 0;
    int  x = 1;
    int  i;
    
    // 10のcol乗を求める
    for(i=1;i<col;i++){
        x = x * 10;
    }
    
    rtc = (n / x) % 10;
    
    return rtc;
}

int main(){
    int  n;
    int  x;
    
    printf("INPUT NUMBER(1000 - 99999) : ");
    scanf("%d",&n);                             // 1234     12345
    
    x = selNumber(n,3);                         // x : 2    x : 3
    
    printf("x : %d\n",x);
    
    return 0;
}
