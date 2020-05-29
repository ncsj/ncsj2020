//
//  ex321.cpp
//  Ex32
//
//  Created by 瀬川健児 on 2020/05/28.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "mylib.hpp"

int main(){
    using namespace MyLib;
    
    try{
        String  s;
        String  apple = "Apple";
        String  pine  = "Pine";
        String  price = "580";
        
        s = pine + apple;
        
        int n = price.number();     // String::number()のバグは解消済み。
        
        printf("s : %s\n",s.get());
        printf("price : %d\n",n);
        
        printf("----------\n");
        
        List <String> list;
        
        list.add(apple);
        list.add(pine);
        list.add(s);
        list.add(price);
        
        for(int i=0;i<list.size();i++){
            String str = list.get(i);
            printf("[%d] %s\n",i,str.get());
        }
    }
    catch(Exception &ex){
        printf("ERROR!\n");
    }
    return 0;
}
