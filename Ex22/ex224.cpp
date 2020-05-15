//
//  ex224.cpp
//  Ex22
//
//  Created by 瀬川健児 on 2020/05/13.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X{
public:
    virtual void f() = 0;
};

class Y : public X{
public:
    void f(){ printf("Y::f()\n"); }
};

class Z : public X{
public:
    void f(){ printf("Z::f()\n"); }
};

int main(){
    Y y;
    Z z;
    
    X  *p;
    
    p = &y;
    p->f();
    
    p = &z;
    p->f();
    
    return 0;
}
