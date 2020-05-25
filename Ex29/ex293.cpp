//
//  ex293.cpp
//  Ex29
//
//  Created by 瀬川健児 on 2020/05/25.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

// 脊椎動物
class Vertebrate{
public:
    virtual void eat(){ printf("Vertebrate::eat()!\n"); };
};

// 哺乳類
class Mammal : virtual public Vertebrate{
};

// 魚類
class Fish : public virtual Vertebrate{
};

class Unagi : public Fish{
public:
    virtual  void  move(){ printf("<:~~~~~~~~<\n"); }
};

class Inu : public Mammal{
public:
    virtual void walk(){ printf("^.^\n"); }
};

class UnagiInu :public Unagi,public Inu{
};

int main(){
    UnagiInu  ui;
    
    ui.move();
    ui.walk();
    
    ui.eat();
    // ui.Unagi::eat();
    // ui.Inu::eat();
    
    return 0;
}
