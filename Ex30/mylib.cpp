//
//  mylib.cpp
//  Ex30
//
//  Created by 瀬川健児 on 2020/05/26.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "mylib.h"

String::String(){
    s = NULL;
}

String::String(const String &r){
    size_t len = strlen(r.s);
    s = new char [len+1];
    
    strcpy(s,r.s);
}

String::String(const char *s){
    size_t len = strlen(s);
    this->s = new char [len+1];
    
    strcpy(this->s,s);
}

String::~String(){
    if(s != NULL){
        delete [] s;
    }
}

String &String::operator = (const String &r){
    if(s != NULL){
        delete [] s;
    }
    s = new char [strlen(r.s)+1];
    strcpy(s,r.s);
    
    return *this;
}

int  String::length(){
    int  len = 0;
    if(s != NULL){
        while(*(s+len)!=0x00){
            len++;
        }
    }
    return len;
}

void String::print(){
    if(s != NULL){
        printf("%s\n",s);
    }
}

