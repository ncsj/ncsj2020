//
//  ex225.cpp
//  Ex22
//
//  Created by 瀬川健児 on 2020/05/13.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class Mammal{
public:
    virtual void eat() = 0;
};

class PetShop{
public:
    void meal(Mammal *p){
        p->eat();
    }
};

class Felis : public Mammal{
public:
    void eat(){ printf("pecha pecha\n"); }
};

class Canis : public Mammal{
public:
    void eat(){ printf("gatsu gatsu\n"); }
};


int main(){
    PetShop nojima;
    Felis tom;
    Canis tama;
    
    nojima.meal(&tom);
    nojima.meal(&tama);
    
    return 0;
}
