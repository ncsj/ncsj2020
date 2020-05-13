#include <stdio.h>

int checkCol(int n){
    int r;
    int x = 1;
    int i;
    
    for(i=0;i<9;i++){
        r = n / x;
        if(r == 0){
            break;
        }
        else{
            x = x * 10;
        }
    }
    
    return i;
}

int  getCol(int n,int col){
    int  rtc = 0;
    int  x = 1;
    int  i;
    
    // 10のcol乗を求める
    for(i=0;i<col;i++){
        x = x * 10;
    }
    
    rtc = (n / x) % 10;
    
    return rtc;
}


int main(){
    int  num;
    int  col;
    int  n;
    int  i;
    char number[10];
    
    printf("INPUT NUMBER : ");
    scanf("%d",&num);
    
    col = checkCol(num);
    printf("col : %d\n",col);
    
    
    printf("------\n");
    
    for(i=0;i<col;i++){
        n = getCol(num,i);
        printf("%d\n",n);
        
        number[col-(i+1)] = 0x30 + (char)n;
    }
    number[col] = 0x00;

    printf("NUMBER : %s\n",number);
    
    return 0;
}
