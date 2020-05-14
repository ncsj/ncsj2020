#include <stdio.h>

int summary(const int *p,int max){
    int  i;
    int  sum = 0;
    
    for(i=0;i<max;i++){
        sum = sum + *(p+i);
    }
    
    return sum;
}

int main(){
    int array[] = {10,2,30,4,50,6,70,80,9,100,110,-10,-100,-1,0};
    int sum;
    
    sum = summary(array,11);
    
    printf("sum : %d\n",sum);
    return 0;
}
