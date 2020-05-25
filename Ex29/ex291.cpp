//
//  ex291.cpp
//  Ex29
//
//  Created by 瀬川健児 on 2020/05/25.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X{
public:
    X(){ printf("X()\n"); }
    X(int x){ printf("x : %d\n",x); }
};

class Y :public X{
public:
    Y(){ printf("Y()\n"); }
    Y(int);
};

class Z :public Y{
public:
    Z(){ printf("Z()\n"); }
    Z(int x,int y,int z) : Y(x){ printf("Z:%d,%d,%d\n",x,y,z);}
};

Y::Y(int x) : X(x){
    printf("x --- %d\n",x);
}


int main(){
    
    Z(100,200,300);
    
    return 0;
}
