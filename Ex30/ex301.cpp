//
//  ex301.cpp
//  Ex30
//
//  Created by 瀬川健児 on 2020/05/26.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X{
public:
    X(){ printf("X()\n"); }
    virtual ~X(){ printf("~X()\n"); }
    
    virtual void f(){ printf("X::f()\n"); }
    virtual void fx() = 0;
};

class Y{
public:
    Y(){ printf("Y()\n"); }
    virtual ~Y(){ printf("~Y()\n"); }
    
    virtual void f(){ printf("Y::f()\n"); }
    virtual void fy() = 0;
};

class XY :public X,public Y{
public:
    XY(){ printf("XY()\n"); }
    ~XY(){ printf("~XY()\n"); }
    
    virtual void f();
    
    virtual void fx(){ printf("fx()\n"); }
    virtual void fy(){ printf("fy()\n"); }
};

void XY::f(){
    printf("***** ここでは独自のf()関数を実装しています。 *****\n");
    printf("これは、Xのf()を実行しています。 > ");
    X::f();
    printf("これは、Yのf()を実行しています。 > ");
    Y::f();
    printf("***** ここまでがf()関数の実行内容です。*****\n");
}

void  fx(X *p){
    p->fx();
}

void  fy(Y *p){
    p->fy();
}


int main(){
    XY  xy;
    xy.f();
    printf("-------------\n");
    
    fx(&xy);    
    fy(&xy);
    
    return 0;
}
