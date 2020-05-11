#include <stdio.h>

int main(){
    /* 列挙 (enumeration)*/
    const int array [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,-1};
    int  i;
    int  sum = 0;
    int  ave;
    int  rem;
    int  m = 0;
    
    for(i=0;array[i]>-1;i++){
        printf("[%d] : %d\n",i,array[i]);
        sum = sum + array[i];
    }
    ave = sum / i;
    rem = sum % i;
    if(rem > 0){
        m = (rem * 10) / i;
    }
    
    
    printf("sum : %d\n",sum);            /* 210 */
    printf("ave : %d.%d\n",ave,m);       /* 10.5 */
    return 0;
}
