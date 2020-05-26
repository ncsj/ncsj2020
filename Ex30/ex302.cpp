//
//  ex302.cpp
//  Ex30
//
//  Created by 瀬川健児 on 2020/05/26.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>
#include "mylib.h"

class Container{
public:
    String  *p;
    Container  *next = NULL;
    
    Container(String *p){ this->p = p; next=NULL; }
    virtual ~Container(){ printf("delete : "); p->print(); }
};

class MyList{
    Container *p = NULL;
public:
    virtual ~MyList();
    void add(String *);
    void listup();
    int  size();
};

MyList::~MyList(){
    if(p != NULL){
        Container *cur = p;
        while(cur != NULL){
            Container  *np = cur;
            cur = cur->next;
            
            delete np;
        }
    }
}

void MyList::add(String *s){
    Container  *cp = new Container( s );
    
    int count = 1;
    if(p == NULL){
        p = cp;
        count++;
    }
    else{
        Container *cur = p;
        while(cur->next != NULL){
            cur = cur->next;
            count++;
        }
        cur->next = cp;
    }
    
}

void MyList::listup(){
    Container *cur = p;
    
    int i = 1;
    while(cur != NULL){
        printf("[%d] ",i);
        cur->p->print();
        
        cur = cur->next;
        i++;
    }
}

int  MyList::size(){
    Container *cur = p;
    
    int i = 0;
    while(cur != NULL){
        cur = cur->next;
        i++;
    }
    return i;
}


int main(){
    String  apple = "Apple";
    String  banana = "Banana";
    String  candy  = "Candy";
    String  donuts = "Donuts";
    
    MyList mlist;
    
    mlist.add(&apple);
    mlist.add(&banana);
    mlist.add(&candy);
    mlist.add(&donuts);
    
    mlist.listup();
    
    return 0;
}
