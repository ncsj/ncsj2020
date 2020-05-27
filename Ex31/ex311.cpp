//
//  ex311.cpp
//  Ex31
//
//  Created by 瀬川健児 on 2020/05/27.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
//  まずは、継承について考えます。
//  ここまでに詳しくは触れていなかったアクセス属性について
//  少々詳しく見ていきます。

#include <stdio.h>

class X{
private:
    int  x;
public:
    virtual void f(){ x = 0; printf("f()\n"); }
};

class Y : public X{
public:
    void ff(){ printf("ff()\n"); f(); }
};

class Z :public Y{
public:
    void fff(){ printf("fff()\n"); f(); }
};

class A{
protected:
    int  x;
public:
    virtual void f(){ x = 0; }
};

class B :protected A{
public:
    void ff(){ x=0; f(); }
};

class C :public B{
public:
    void fff(){ x=0; f(); ff();}
};



int main(){
    X x;
    x.f();
    
    Y  y;
    y.f();
    y.ff();
    
    C b;
    // b.x = 100;
    b.f();
    
    return 0;
}
