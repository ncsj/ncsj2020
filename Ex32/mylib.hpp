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
    class String;
    class Container;
    class List;

    /*  */
    String operator + (const String &,const String &);
}

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
    int number();       // 例外処理もあり！
    
    // String operator + (const String &,const String &)をfriendに指定する。
    friend String operator + (const String &,const String &);
};

/*
 コンテナー（Container）クラス
 */
class Container{
public:
};

/*
 リスト（List）クラス
 */
class List{
public:
};

#endif /* mylib_hpp */
