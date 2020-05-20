//
//  ex261.cpp
//  Ex26
//
//  Created by 瀬川健児 on 2020/05/20.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "mystring.h"

int main(){
    Console con;
    
    // String filename = "/Users/student/Desktop/Ex26/Ex26/sample.txt";
    String filename = "/Users/segawakenji/Desktop/Ex26/Ex26/sample.txt";
    FileOutput fo(filename);
    
    String message = "Hello,World - ????";
    
    con << message;
    fo << message;
    
    return 0;
}
