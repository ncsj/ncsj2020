//
//  ex242.cpp
//  Ex24
//
//  Created by 瀬川健児 on 2020/05/18.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
//  わからなくなりそうな人は見ていてね。
//  ここでは、staticというキーワードについて、考えてみます。

#include <stdio.h>


class X{
    int  y;
public:
    static int x;
    static void f();
};
int X::x;                   // この１行がないと、エラーになる。

void X::f(){
    //  y = 0;              ここでは、「ダイナミックな」変数は存在していないので、使用できない。
    printf("X::f()\n");
}

int  main(){
    
    X::f();
    
    X::x = 12345;
    
    printf("x : %d\n",X::x);
    
    X  x1;
    
    printf("x : %d\n",x1.x);
    
    x1.f();
    
    return 0;
}
