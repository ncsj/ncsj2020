//
//  menu.cpp
//  STEPs
//
//  Created by 瀬川健児 on 2020/06/04.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "menu.h"

String::String(){
    s = NULL;
}

String::String(const String &r){
    size_t  len = strlen(r.s);
    s = new char [len+1];
    strcpy(s,r.s);
}

String::String(const char *s){
    size_t  len = strlen(s);
    this->s = new char [len+1];
    strcpy(this->s,s);
}

String::~String(){
    if(s != NULL){
        delete [] s;
    }
}

String  &String::operator = (const String &r){
    if(s!=NULL){
        delete [] s;
    }
    s = new char [strlen(r.s)+1];
    strcpy(s,r.s);
    
    return *this;
}

char    *String::get(){
    return s;
}

int     String::length(){
    int rtc = 0;
    
    if(s != NULL){
        while(*(s+rtc) != 0x00){
            rtc++;
        }
    }
    
    return rtc;
}

String operator + (const String &s1,const String &s2){
    String str;
    size_t len1 = 0;
    size_t len2 = 0;
    if(s1.s != NULL){
        len1 = strlen(s1.s);
    }
    if(s2.s != NULL){
        len2 = strlen(s2.s);
    }

    size_t len = len1 + len2;
    str.s = new char [len+1];
    sprintf(str.s,"%s%s",s1.s,s2.s);
    return str;
}

Menu::~Menu(){
    if(item != NULL){
        MenuItem * cur = item;
        while(cur != NULL){
            MenuItem * prev = cur;
            cur = cur->next();
            delete prev;
        }
        
        item = NULL;
    }
}

void Menu::add(MenuItem *item){
    if(this->item == NULL){
        this->item = item;
    }
    else{
        MenuItem *cur = this->item;
        while(cur->next() != NULL){
            cur = cur->next();
        }
        
        cur->next(item);
    }
}

void Menu::add(const String &r){
    add(new MenuItem(r));
}

int Menu::show(){
    if(this->item == NULL){
        printf("NO MENU ITEM.");
    }
    else{
        int i = 1;
        String  s = "";
        MenuItem *cur = this->item;
        while(cur != NULL){
            char num[10];
            sprintf(num,"%d",i);
            s = s + num + ":" + cur->getTitle() + " ";
     
            i++;
            cur = cur->next();
        }
        
        printf("%s  9:EXIT\n",s.get());
        
    }
    
    printf("SELECT NUMBER > ");
    int  rtc;
    scanf("%d",&rtc);
    
    return rtc;
}

MenuItem::MenuItem(const String &title){
    this->title = title;
}

MenuItem  *MenuItem::next(){
    return this->np;
}

void MenuItem::next(MenuItem *p){
    this->np = p;
}

String MenuItem::getTitle(){
    return title;
}

