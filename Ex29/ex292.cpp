//
//  ex292.cpp
//  Ex29
//
//  Created by 瀬川健児 on 2020/05/25.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

int plus(int x,int y=0){
    return x + y;
}

void  f(int x=0,int y=0,int z=0){
    printf("%d,%d,%d\n",x,y,z);
}

class X{
public:
    X(){ printf("X()\n"); }
    X(int,int,int);
};

X::X(int x,int y=0,int z=0){
    printf("%d,%d,%d\n",x,y,z);
}

int main(){
    int  ans = plus(10);
    printf("%d + %d = %d\n",10,0,ans);
    
    f();
    f(100);
    f(100,200);
    f(100,200,300);
    
    printf("-----\n");
    {
        X x;
        X  xx(1);
        X  xxx(1,2);
        X  xxxx(1,2,3);
    }
    
    return 0;
}

