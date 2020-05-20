//
//  mystring.h
//  Ex25
//
//  Created by 瀬川健児 on 2020/05/19.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#ifndef mystring_h
#define mystring_h

class Console;              // consoleクラスの宣言
class String;               // Stringクラスの宣言
class Printable;            // メンバー関数（print()）の実装を指定する抽象クラス

// String同士を連結する演算子、＋をオーバーロード
String operator + (const String &,const String &);

/*
 コンソールへ出力するクラス
 */
class Console{
public:
    Printable &operator << (Printable &);
};

/*
 抽象クラスとして実装
 */
class Printable{
public:
    // void print()はここでは純粋仮想関数として定義する。
    virtual void print() = 0;
};


/*
 Stringクラスの定義
 */
class String : public Printable{
private:
    char  *s;
public:
    String();
    String(const String &);
    String(const char *);
    String(int);
    ~String();
    
    String &operator = (const String &);
    int  length();
    
    // Printableで指定されるメンバー関数を実装
    void print();
    
    // 以下はメンバー関数ではない
    friend String operator + (const String &,const String &);
};


#endif /* mystring_h */
