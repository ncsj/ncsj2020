//
//  ex281.cpp
//  Ex28
//
//  Created by 瀬川健児 on 2020/05/22.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X;
class Y;
class Z;

class Y{
public:
    Y(){ printf("Y()\n"); }
    virtual ~Y(){ printf("~Y()\n"); }
};

class Z{
public:
    Z(){ printf("Z()\n"); }
    virtual ~Z(){ printf("~Z()\n"); }
};

class X{
    Y  y;
    Z  z;
public:
    X(){ printf("X()\n"); }
    virtual ~X(){ printf("~X()\n"); }
};

class A{
public:
    A(){ printf("A()\n"); }
    virtual ~A(){ printf("~A()\n"); }
};

class B :public A{
public:
    B(){ printf("B()\n"); }
    virtual ~B(){ printf("~B()\n"); }
};

class C :public B{
public:
    C(){ printf("C()\n"); }
    virtual ~C(){ printf("~C()\n"); }
};


int main(){
    /**
    X  *p  = new X();
    delete p;
    **/
    {
        X x;
    }
    printf("----------\n");
    {
        C  c;
    }
    return 0;
}
