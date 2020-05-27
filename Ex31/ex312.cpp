//
//  ex312.cpp
//  Ex31
//
//  Created by 瀬川健児 on 2020/05/27.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

namespace  ABC{
void f(){
    printf("Hello,World!\n");
}

class X{
public:
    X(){ printf("ABC::X()\n"); }
};
}

namespace  XYZ{
void f(){
    printf("こんにちは。\n");
}

class X{
public:
    X(){ printf("XYZ::X()\n"); }
};
}

void  f1(){
    using namespace ABC;
    
    f();
}

void f2(){
    using namespace XYZ;
    
    f();
}

void f3(){
    using namespace ABC;
    using namespace XYZ;
    
    ABC::f();
    XYZ::f();
}

void f4(){
    using namespace  ABC;
    using namespace  XYZ;

    XYZ::X  x;
}


namespace  A{
    namespace B{
        namespace C{
        
        void f();

        }
    }
}

void A::B::C::f(){
    printf("A.B.C.f()\n");
}


int main(){
    f2();
    f1();
    
    printf("----------\n");
    
    f4();
    
    printf("----------\n");
    ABC::f();
    XYZ::f();
    
    printf("----------\n");
    
    
    {   // 匿名のブロックです。
        // CBAは、A::B::Cのエイリアス（alias：別名）です。
        namespace CBA = A::B::C;
        using namespace CBA;
        f();
    }
    
    CBA::f();

    return 0;
}
