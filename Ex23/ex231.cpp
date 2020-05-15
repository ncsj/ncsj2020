//
//  ex231.cpp
//  Ex23
//
//  Created by 瀬川健児 on 2020/05/16.
//  Copyright © 2020 瀬川健児. All rights reserved.
//
//  アップロード前に、プロジェクトが壊れてしまいました。
//  授業でやった内容を再現したつもりですが、
//  細かいところは相違があると思います。

#include <stdio.h>

class String{
    char  buff[128];
public:
    String();
    String(const char *);
    String(int);
    
    void set(const char *);
    void print();
};

class Console{
public:
    String operator << (String);
};

int main(){
    String  s1 = "Apple";
    String  s2 = 12345;
    
    s1.print();
    s2.print();
    
    return 0;
}

String::String(){
    for(int i=0;i<128;i++){
        buff[i] = 0x00;
    }
}

String::String(const char *s){
    for(int i=0;i<128;i++){
        buff[i] = *(s+i);
        
        if((*s+i)==0x00){
            break;
        }
    }
}

String::String(int n){
    sprintf(buff,"%d",n);
}

void String::set(const char *s){
    sprintf(buff,"%s",s);
}

void String::print(){
    printf("%s\n",buff);
}

String Console::operator << (String s){
    s.print();
    return s;
}
