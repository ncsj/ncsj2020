//
//  ex272.cpp
//  Ex27
//
//  Created by 瀬川健児 on 2020/05/21.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class X{
public:
    X(){ printf("X()\n"); }
    virtual ~X(){ printf("~X()\n"); }
};

class Y : public X{
public:
    Y(){ printf("Y()\n"); }
    ~Y(){ printf("~Y()\n"); }
};

class Z : public Y{
public:
    Z(){ printf("Z()\n"); }
    ~Z(){ printf("~Z()\n"); }
};

int main1(){
    Y y;
    return 0;
}

int main(){
    Y *p;
    p = new Z();
    
    delete p;
    
    return 0;
}
