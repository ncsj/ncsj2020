//
//  ex282.cpp
//  Ex28
//
//  Created by 瀬川健児 on 2020/05/22.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
//  ここでは、例外処理の実験を行う！

#include <stdio.h>

class X{
public:
    X(){ printf("X()\n"); }
    virtual ~X(){ printf("~X()\n"); }
};

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

class XYZ :public X{
    Y  y;
    Z  z;
public:
    XYZ(int);
    ~XYZ(){ printf("~XYZ()\n"); }
    void f(){ printf("X::f()\n"); }
};

XYZ::XYZ(int x){
    if(x > 100){
        throw "x is over 100.";
    }
    
    printf("SUCCESS!\n");
}

int main(){
    int  x;
    printf("x : ");
    scanf("%d",&x);
    
    try{
        XYZ  xyz(x);
        xyz.f();
    }
    catch(const char *s){
        printf("%s\n",s);
    }
    
    return 0;
}


void f(){
    int  x;
    int  y;
    
    printf("x : ");
    scanf("%d",&x);
    
    printf("y : ");
    scanf("%d",&y);

    try{
        if(x > 100){
            // printf("x(%d) is over 100.\n",x);
            
            throw "x is over 100.";
        }
        printf("%d + %d = %d\n",x,y,(x+y));
    }
    catch(const char *s){
        printf("ERROR : %s\n",s);
    }
}

void ff(){
    int  x;
    int  y;
    
    printf("x : ");
    scanf("%d",&x);
    
    printf("y : ");
    scanf("%d",&y);

    if(x > 100){
        throw "x is over 100.";
        
    }
    
    // 以下のコードは、x > 100の時には実行されない！
    printf("%d + %d = %d\n",x,y,(x+y));
}


int main1(){
    
    f();
    
    try{
        ff();
    }
    catch(const char *s){
        printf("%s\n",s);
    }
    
    return 0;
}
