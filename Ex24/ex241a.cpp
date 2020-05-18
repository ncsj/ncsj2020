//
//  ex241a.cpp
//  Ex24
//
//  Created by 瀬川健児 on 2020/05/18.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
// このプログラムは、参照（リファレンス）を理解するためだけに記述します。
// 皆さんの方で、記述しなくて良いものです。

#include <stdio.h>

void  f(int &r){
    printf("r : %d\n",r);
    r = r * 2;
}

class X{
public:
    X(){ printf("X()\n"); }
    X(const X &r){ printf("X(const X &)\n"); }
    ~X(){ printf("~X()\n"); }
};

/**
class Y{
    
};
**/
// 上記の定義だけで、以下の内容は作られている。
class Y{
public:
    Y();
    Y(const Y &);
    ~Y();
    
    Y &operator = (const Y &);
};

void f(X &x2){
    ;
}

int main(){
    X x1;
    
    printf("-----\n");
    f(x1);
    printf("-----\n");

}

int xmain(){
    int  x = 0;
    int  &r = x;        // 定義した時に参照先を決めないといけない。
    
    r = 123;
    printf("x : %d\n",x);
    
    x = 321;
    printf("r : %d\n",r);
    
    f(r);
    printf("r : %d\n",r);

    return 0;
}
