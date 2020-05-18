//
//  ex241.cpp
//  Ex24
//
//  Created by 瀬川健児 on 2020/05/18.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include <string.h>

class String{
    char  *s;
public:
    String();
    String(const String &);
    ~String();
    String(const char *);
    
    int length();
    static int length(String);
    
    void print();
    
    String &operator = (const String &);
};

int main(){
    String s1 = "Apple";
    s1.print();
    
    printf("length 1 : %d\n",s1.length());
    
    printf("length 2 : %d\n",String::length("banana"));
    
    printf("-----\n");
    
    String s2;
    
    s2 = s1;
    s2.print();
    
    return 0;
}

String &String::operator = (const String &r){
    printf("String &operator = (const String &)\n");
    if(s != NULL){
        delete [] s;
    }
    
    s = new char [strlen(r.s)+1];
    strcpy(s,r.s);
    
    return *this;
}

int String::length(String s){
    return s.length();
}

String::String(){
    s = NULL;
}

String::String(const String &r){
    printf("String(const String & : %s)\n",r.s);
    size_t len = strlen(r.s);
    
    s = new char [len+1];
    for(int i=0;i<len+1;i++){
        *(s+i) = *(r.s+i);
    }
}

String::~String(){
    if(s != NULL){
        delete [] s;
    }
}

String::String(const char *p){
    size_t len = strlen( p );
    s = new char [len+1];
    int i=0;
    while(*(p+i) != 0x00){
        *(s+i) = *(p+i);
        i++;
    }
    *(s+i) = 0x00;
}

int String::length(){
    int len = 0;
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

