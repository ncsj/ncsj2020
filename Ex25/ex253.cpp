//
//  ex253.cpp
//  Ex25
//
//  Created by 瀬川健児 on 2020/05/19.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
//  このプログラムは、「継承」の危うさを理解するために作成するものです。
//  宵子の皆さんは、決して真似しないように！
//

#include <stdio.h>

class  PLUS{
public:
    int  plus(int x,int y){ return x + y; }
};

class PLUSMINUS : public PLUS{
public:
    int minus(int x,int y){ return x - y; }
};

class PlusMinusMultiply : public PLUSMINUS{
public:
    int multiply(int x,int y){ return x * y; }
};

class CALC : public PlusMinusMultiply{
public:
    int divide(int x,int y){ return x / y; }
};

int main(){
    CALC calc;
    
    int x;
    int y;
    
    printf("x : ");
    scanf("%d",&x);
    
    printf("y : ");
    scanf("%d",&y);
    
    printf("%d + %d = %d\n",x,y,calc.plus(x,y));
    printf("%d - %d = %d\n",x,y,calc.minus(x,y));
    printf("%d * %d = %d\n",x,y,calc.multiply(x,y));
    printf("%d / %d = %d\n",x,y,calc.divide(x,y));

    
    return 0;
}
