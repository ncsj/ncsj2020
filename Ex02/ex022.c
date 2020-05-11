#include <stdio.h>

int main(){
    int  x;

    x = 0;
    if(x < 10){
        printf("x : %d\n",x);
        x++;
    }
    /**
            条件式（比較）の書き方
        x < 10      x > 10
        x <= 10   x >= 10
        x != 10     x == 10
     */
    
    printf("x : %d\n",x);
    
    return 0;
}
