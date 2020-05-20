//
//  ex262.cpp
//  Ex26
//
//  Created by 瀬川健児 on 2020/05/20.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "mystring.h"

Output *menu(){
    Output *out = NULL;
    int id;

    Provider  prov;
    String fname = "/Users/segawakenji/Desktop/Ex26/Ex26/hello.txt";

    printf("0:CONSOLE  1:FILE\n");
    printf("SELECT NUMBER : ");
    scanf("%d",&id);
    
    switch( id ){
        case 0:
            out = prov.get(id);
            break;
        case 1:
            out = prov.get(id,fname);
            break;
        default:
            out = NULL;
            break;
    }
    return out;
}

int main(){
    Output  *out = NULL;

    String s = "+ Hello,World.";
    int loop = 1;
    while(loop == 1){
        out = menu();
        if(out != NULL){
    
            *out << s;
            delete out;
        }
        else{
            loop = 0;
        }
    }
    
    return 0;
}
