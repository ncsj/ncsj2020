//
//  step1.cpp
//  STEPs
//
//  Created by 瀬川健児 on 2020/06/04.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include "menu.h"

int main(){
    {
        Menu menu;
        
        menu.add("+");
        menu.add("-");
        menu.add("*");
        menu.add("/");
        
        int m = menu.show();
        printf("m : %d\n",m);
    }
    
    {
        Menu menu;
        const char *items[] = {"New","Edit","Del","List"};
        
        for(int i=0;i<4;i++){
            menu.add(items[i]);
        }
        
        int m = menu.show();
        printf("m : %d\n",m);
    }
}
