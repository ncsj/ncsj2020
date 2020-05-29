//
//  mylib.cpp
//  Ex32
//
//  Created by 瀬川健児 on 2020/05/28.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include "mylib.hpp"

using namespace MyLib;

/**
 デフォルトコンストラクター
 */
String::String(){
    s = NULL;
}

/*
 デストラクター
 */
String::~String(){
    if(s != NULL){
        delete [] s;
    }
}

/*
 コピーコンストラクター
 */
String::String(const String &r){
    size_t  len = strlen(r.s);
    s = new char [len+1];
    strcpy(s,r.s);
}

/*
 文字列（char *）からインスタンスを生成するコンストラクター
 */
String::String(const char *s){
    size_t len = strlen(s);
    this->s = new char [len+1];
    strcpy(this->s,s);
}

/*
 整数値（int）からインスタンスを生成するコンストラクター
 */
String::String(int n){
    char  buff[12];
    sprintf(buff,"%d",n);
    
    size_t len = strlen(buff);
    s = new char [len+1];
    strcpy(s,buff);
}

/*
 代入演算子（=）のオーバーロード
 メンバー関数として実装
 */
String &String::operator = (const String &r){
    if(s != NULL){
        delete [] s;
    }
    s = new char [strlen(r.s) + 1];
    strcpy(s,r.s);
    return *this;
}

/*
 インスタンスが保持している文字列（char *）を返す関数
 */
char *String::get(){
    return this->s;
}

/*
 保持している文字列の長さを返す関数
 何も設定されていない場合は、0を返す。
 */
int String::length(){
    int len = 0;
    while(*(s+len) != 0x00){
        len++;
    }
    return len;
}

/*
 この関数は、String::number()関数のために作成
 汎用的に利用するには、この関数の置き場所も考えないといけない。
 とりあえず、名前空間（MyLib）の中のものとする。
 */
int MyLib::power(int v,int n){
    int value = 1;
    for(int i=0;i<n;i++){
        value = value * v;
    }
    return value;
}

/*
 Stringクラスのインスタンスが保持している文字列が、
 整数値へ変換しても大丈夫かをチェックする。
 */
int  String::check(){
    int rtc = 0;
    char *p = s;
    while(*p != 0x00){
        if((*p >= '0') && (*p <= '9')){
            ;
        }
        else{
            rtc = ERROR;
        }
        p++;
    }
    return rtc;
}

/*
 保持している文字列を、整数値（int）に変換する関数。
 */
int String::number() throw(Exception){
    int rtc = check();
    if(rtc == ERROR){
        throw Exception();
    }
    
    int  sum = 0;
    int len = (int)strlen(s);
    
    for(int i=0;i<len;i++){
        // 以下の１行の最後の部分（power()の２つ目の引数）がまちがえていました。
        // int v = (*(s+i) - 0x30) * power(10,len-1);
        int v = (*(s+i) - 0x30) * power(10,len-(i+1));
        sum = sum + v;
    }
    
    return sum;
}

/*
 加算（+）演算子のオーバーロード
 Stringのインスタンス同士を連結する関数
 */
String MyLib::operator + (const String &s1,const String &s2){
    String str;
    
    size_t len = strlen(s1.s) + strlen(s2.s);
    str.s = new char [len + 1];
    sprintf(str.s,"%s%s",s1.s,s2.s);
    
    return str;
}


