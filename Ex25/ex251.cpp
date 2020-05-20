//
//  ex251.cpp
//  Ex25
//
//  Created by 瀬川健児 on 2020/05/19.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include "mystring.h"

int main(){
    String s1 = "Apple";
    String s2 = 12345;

    Console  console;

    console << s1;
    console << s2;
    
    String s;
    
    s = s1 + s2;
    console << s;
    
    s = s + 100;
    console << s;
    
    String line = "----------";
    console << line;
    
    String fruits;
    String apple = "Apple";
    String pine = "Pine";
    
    fruits = pine + apple;
    
    console << fruits;
    return 0;
}
