//
//  ex222.cpp
//  Ex22
//
//  Created by 瀬川健児 on 2020/05/13.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X{
public:
    int  n;
    void f(){ printf("f()\n"); }
};

class Y :public X{
public:
    void print(){ printf("n : %d\n",n); }
};

int main(){
    X  x;
    Y  y;
    
    x.f();
    y.f();
    
    x.n = 100;
    y.n = 200;
    
    y.print();
    
    return 0;
}
