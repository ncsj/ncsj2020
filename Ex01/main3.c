#include <stdio.h>

/*
 整数型の変数
 int                    コンパイラーにより異なる
 short                  16bit
 long                   32bit
 
 実数（浮動小数点）
 float                  32bit
 double                 64bit
 
 文字
 char                   8bit
 
 なんでもない
 void
 */


int main() {
    int  x;
    int  y;
    int  z;
    
    printf("INPUT x : ");
    scanf("%d",&x);
    
    printf("INPUT y : ");
    scanf("%d",&y);
    
    z = x + y;
    
    printf("x : %d\n",x);
    
    printf("%d + %d = %d\n",x,y,z);
    
    return 0;
}
