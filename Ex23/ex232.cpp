//
//  ex232.cpp
//  Ex23
//
//  Created by 瀬川健児 on 2020/05/16.
//  Copyright © 2020 瀬川健児. All rights reserved.
//  アップロード前に、プロジェクトが壊れてしまいました。
//  授業でやった内容を再現したつもりですが、
//  細かいところは相違があると思います。

#include <stdio.h>

class X{
public:
    X();
    ~X();
};

int _main(){
    X  *p = NULL;
    printf("----- START -----\n");
    p = new X;
    delete p;
    printf("----- FINISH -----\n");
    
    return 0;
}

X::X(){
    printf("X()\n");
}

X::~X(){
    printf("~X()\n");
}
