//
//  ex243.cpp
//  Ex24
//
//  Created by 瀬川健児 on 2020/05/18.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X{
public:
    void f(){ printf("HELLO!\n"); }
    X *me();
};

X *X::me(){
    X *p = NULL;
    p = this;           // thisは自分（実体）へのポインターです。
    return p;
}

int main(){
    X  x;
    X  *p;
    
    p = x.me();
    
    p->f();
    
    return 0;
}
