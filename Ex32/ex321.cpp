//
//  ex321.cpp
//  Ex32
//
//  Created by 瀬川健児 on 2020/05/28.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "mylib.hpp"

/* これから記述するクラスと関数は、一時的なもです。
 main()関数までは、例外を理解するための例題です。
 */
class Exception{
public:
    Exception(){ printf("Exception!\n"); }
};

/*
 引数 x:int    100未満の場合は成功。
    成功した場合は0を、失敗した場合は-1を返す。
 */
void f(int x) throw (Exception){
    if(x < 100){
        printf("x : %d\n",x);
    }
    else{
        throw Exception();
    }
}

int main(){
    int  x;
    printf("x : ");
    scanf("%d",&x);
    
    try{
        f(x);
    }
    catch(Exception &r){
        printf("The Exception is Caught.\n");
    }
    
    return 0;
}

int _main(){
    using namespace MyLib;
    
    String  s;
    String  apple = "Apple";
    String  pine  = "Pine";
    String  price = 580;
    
    s = pine + apple;
    
    int n = price.number();     // String::number()のバグは解消済み。
    
    printf("s : %s\n",s.get());
    printf("price : %d\n",n);
    
    return 0;
}
