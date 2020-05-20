//
//  mystring.cpp
//  Ex25
//
//  Created by 瀬川健児 on 2020/05/19.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "mystring.h"

String operator + (const String &r1,const String&r2){
    String  str;
    
    int  len1 = 0;
    int  len2 = 0;
    
    if(r1.s != NULL){
        len1 = (int)strlen(r1.s);
    }
    
    if(r2.s != NULL){
        len2 = (int)strlen(r2.s);
    }
    
    str.s = new char [len1+len2+1];

    if(len1 == 0){
        sprintf(str.s,"%s",r2.s);
    }
    else{
        sprintf(str.s,"%s%s",r1.s,r2.s);
    }
    
    return str;
}


Printable &Console::operator << (Printable &r){
    r.print();
    return r;
}


String::String(){
    s = NULL;
}

String::String(const String &r){
    s = new char [strlen(r.s)+1];
    strcpy(s,r.s);
}

String::String(const char *p){
    s = new char [strlen(p)+1];
    strcpy(s,p);
}

String::String(int n){
    char buff[10];
    sprintf(buff,"%d",n);
    
    s = new char[strlen(buff)+1];
    strcpy(s,buff);
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
    int len = 0;
    
    while(*(s+len) != 0x00){
        len++;
    }
    
    return len;
}

void String::print(){
    if(s != NULL){
        printf("%s\n",s);
    }
}
