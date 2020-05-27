//
//  ex313.cpp
//  Ex31
//
//  Created by 瀬川健児 on 2020/05/27.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
//  テンプレートのさわりだけ

#include <stdio.h>

class Data{
    int  x;
    int  y;
public:
    Data(){ x = y = 0; }
    Data(int x,int y){ this->x = x; this->y = y; }
    friend Data operator + (const Data &,const Data &);
};

Data operator + (const Data &d1, const Data &d2){
    Data data;
    
    data.x = d1.x + d2.x;
    data.y = d1.y + d2.y;
    
    printf("%d,%d\n",data.x,data.y);
    
    return data;
}

Data plus(Data d1,Data d2){
    return d1 + d2;
}

int plus(int x,int y){
    return x + y;
}

template <typename T>
T addition(T x,T y){
    return x + y;
}

int main(){
    Data data;
    int  sum;
    Data d1(100,200);
    Data d2(12,23);
    
    data = addition(d1,d2);

    sum = addition(10,20);
    printf("SUM : %d\n",sum);
    
    return 0;
}
