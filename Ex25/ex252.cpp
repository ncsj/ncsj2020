//
//  ex252.cpp
//  Ex25
//
//  Created by 瀬川健児 on 2020/05/19.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include "mystring.h"

class Data : public Printable{
    int  x;
    int  y;
public:
    Data(){ x = y = 0; }
    void  set(int x,int y){
        this->x = x;
        this->y = y;
    }
    
    void print(){
        printf("%d,%d\n",x,y);
    }
};

int xmain(){
    Data  d1;
    d1.set(100,200);
    
    String s1 = "Apple";
    
    Console con;
    con << d1;
    con << s1;
    
    return 0;
}
