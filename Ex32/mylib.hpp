//
//  mylib.hpp
//  Ex32
//
//  Created by 瀬川健児 on 2020/05/28.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#ifndef mylib_hpp
#define mylib_hpp

#include <stdio.h>
#include <string.h>

/*
 名前空間（namespace）    MyLib
 */
namespace MyLib{
    const int ERROR = -1;               // エラーを表す定数
    class String;                       // 文字列

    template  <class T>
    class Container;

    template  <class T>
    class List;  // リスト構造をラッピングしている
    
class Exception;        //  例外クラス、String::number()で使用

    /* 加算演算子のオーバーロード */
    String operator + (const String &,const String &);
    int power(int,int);     //  冪乗
}

/*
 例外クラス（Exception）
 */
class MyLib::Exception{
public:
    Exception(){ printf("Exception!\n"); }
};

/*
 Stringクラス
 文字列を扱うためのクラス
 namespace : MyLib
 */
class MyLib::String{
    char  *s = NULL;
public:
    String();
    ~String();
    String(const String &);
    String(const char *);
    String(int);
    String &operator = (const String &);
    char *get();
    int length();
    int number() throw(Exception);
    int check();
    
    // String operator + (const String &,const String &)をfriendに指定する。
    friend String operator + (const String &,const String &);
};



/*
 リスト（List）クラス
 */
template  <class T>
class MyLib::List{
    
    Container <T> *bp = NULL;
public:
    void    add(T);
    T       get(int) throw(Exception);
    int     size();
};

/*
 コンテナー（Container）クラス
 */
template <class T>
class MyLib::Container{
    T  str;
    
    Container  *next = NULL;
public:
    Container(const T &r){ str = r; }
    
    Container   *getNext(){ return next; };
    void        setNext(Container *next){ this->next = next; }
    T      get(){ return str; }
};

/*
 以下のListクラスのメンバー関数の実装は、実装ファイル（mylib.cpp）へ移行する予定。
 いまのところ、ここでないとコンパイル時にエラーとなる。
 */
template <class T>
void  MyLib::List<T>::add(T s){
    Container <T> *cp = new Container <T> (s);
    
    if(bp == NULL){
        bp = cp;
    }
    else{
        Container <T> *cur = bp;
        while(cur->getNext() != NULL){
            cur = cur->getNext();
        }
        
        cur->setNext(cp);
    }
}

template <class T>
T MyLib::List<T>::get(int index) throw(Exception){
    T str;
    if(size() > 0){
        int count = 0;
        Container <T> *cur = bp;
        while(cur != NULL){
            if(count == index){
                str = cur->get();
                break;
            }
            else{
                cur = cur->getNext();
                count++;
            }
        }
    }
    else{
        throw Exception();
    }
    return str;
}

template <class T>
int MyLib::List<T>::size(){
    int count = 0;
    
    Container <T> *cur = bp;
    while(cur != NULL){
        count++;
        cur = cur->getNext();
    }
    
    return count;
}


#endif /* mylib_hpp */
