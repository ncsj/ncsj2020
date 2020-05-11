#include <stdio.h>

int main(){
    int  sum;
    int  ave;
    int  i;
    
    sum = 0;
    
    for(i=0;i<10;i++){
        sum = sum + (i+1);
    }
    
    /* 合計を表示する */
    printf("sum : %d\n",sum);
    
    /* 平均を計算し、表示する */
    ave = sum / i;
    printf("ave : %d\n",ave);
    
    return 0;
}
