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
    if(r.s != NULL){
        s = new char [strlen(r.s)+1];
        strcpy(s,r.s);
    }
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

String String::toString(){
    return *this;
}

char *String::get(){
    return s;
}

FileOutput::FileOutput(String &r){
    char *s = r.get();
    strcpy(fname,s);            // ファイル名を保持する
    
    fp = fopen(fname,"w+t");    // ファイルを"w+t"モードで開く
    if(fp == NULL){
        // ファイルを開けなかった場合、fpはNULLになっている。
        printf("FILE OPEN ERROR : %s\n",fname);
    }
}

FileOutput::~FileOutput(){
    if(fp != NULL){
        fclose(fp);
    }
}

Printable  &FileOutput::operator << (Printable &r){
    if(fp != NULL){
        String s = r.toString();
        fprintf(fp,"%s\n",s.get());
    }
    return r;
}

Output *Provider::get(int id){
    Output *p = NULL;
    
    p = new Console;
    
    return p;
}

Output *Provider::get(int id,String fname){
    Output *p = NULL;
    
    switch( id ){
        case 0:
            p = new Console();
            break;
        case 1:
            p = new FileOutput(fname);
            break;
        default:
            break;
    }
    return p;
}

void Output::set(Menu *mp){
    this->mp = mp;
}

void Output::release(){
    if(mp != NULL){
        mp->cleanup();
    }
}

Output &Menu::menu(){
    int id;

    Provider  prov;
    String fname;                           // 未設定  = NULLと同義
    
    // 定数の定義方法
    /*
    const  int  CONSOLE     = 0;        // 定数は定義時に値を決定する
    const  int  FILEOUTPUT  = 1;
    const  int  EXIT        = 9;
    */
    
    printf("%d:CONSOLE  %d:FILE  %d:EXIT\n",CONSOLE,FILEOUTPUT,EXIT);
    printf("SELECT NUMBER : ");
    scanf("%d",&id);
    
    if(id == FILEOUTPUT){
        fname = "/Users/segawakenji/Desktop/Ex27/Ex27/hello.txt";
    }

    out = prov.get(id,fname);
    if(out != NULL){
        out->set(this);
    }
    else{
        stat = BREAK;
    }

    return *out;
}

void Menu::cleanup(){
    if(out != NULL){
        delete out;
        out = NULL;
    }
}

Menu::Menu(){
    stat = CONTINUE;
}

int Menu::status(){
    return stat;
}

