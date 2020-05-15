//
//  ex221.cpp
//  Ex22
//
//  Created by 瀬川健児 on 2020/05/13.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

class  X{
    int  x;
    int  y;
    
public:
    void set(int,int);
    void print();
};

int main(){
    X    x;
    
    x.set(10,20);
    x.print();

    return 0;
}

//  :: はスコープ解決演算子
void X::print(){
    printf("%d,%d\n",x,y);
}

void X::set(int a, int b){
    x = a;
    y = b;
}


