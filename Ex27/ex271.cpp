//
//  ex271.cpp
//  Ex27
//
//  Created by 瀬川健児 on 2020/05/21.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "mystring.h"


int main(){
    Menu m;

    String s = "+ Hello,World.";
    while(1){
        Output &out = m.menu();
        if(m.status() == Menu::CONTINUE){
            out << s;
            out.release();
        }
        else{
            break;
        }
    }
    
    return 0;
}
