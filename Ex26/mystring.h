//
//  mystring.h
//  Ex25
//
//  Created by 瀬川健児 on 2020/05/19.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

#ifndef mystring_h
#define mystring_h

class Output;               // 出力を行うクラスの定義している抽象クラス
class Console;              // consoleクラスの宣言
class String;               // Stringクラスの宣言
class Printable;            // メンバー関数（print()）の実装を指定する抽象クラス
class FileOutput;           // 出力ファイル
class Provider;             // Outputのインスタンス（実体）を生成して、提供するクラス。

// String同士を連結する演算子、＋をオーバーロード
String operator + (const String &,const String &);

/*
 抽象クラスとして実装
 */
class Printable{
public:
    virtual void print() = 0;           // void print()はここでは純粋仮想関数として定義する。
    virtual String toString() = 0;      // print()で出力する内容を、Stringとして返す関数。純粋仮想関数。
};

/*
 出力の機能（関数）を定義している抽象クラス
 このクラスを継承し、定義している純粋仮想関数を実装しているのが、以下のクラスである。
 Console    :   コンソールへの出力を行う。
 FileOutput :   ファイルへの出力を行う。
 */
class Output{
public:
    virtual Printable &operator << (Printable &) = 0;
};


/*
 コンソールへ出力するクラス
 */
class Console : public Output{
public:
    Printable &operator << (Printable &);
};

/*
 ファイル出力を実現するクラス
 ただし、テキスト出力のみ。
 */
class FileOutput : public Output{
private:
    FILE  *fp;
    char fname[128];
public:
    FileOutput(String &);
    ~FileOutput();
    
    Printable &operator << (Printable &);
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
    char *get();            // 保持している文字列のポインタを返す
    
    // Printableで指定されるメンバー関数を実装
    void print();
    String toString();
    
    // 以下はメンバー関数ではない
    friend String operator + (const String &,const String &);
};

/*
 クラス名 : Provider
 */
class Provider{
public:
    Output *get(int);
    Output *get(int,String);
};

#endif /* mystring_h */
