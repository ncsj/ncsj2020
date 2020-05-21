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
class Menu;                 // メニューを実現しているクラス

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
protected:
    Menu  *mp = NULL;
public:
    virtual Printable &operator << (Printable &) = 0;
    void set(Menu *);
    void release();
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
    // 初期値をNULLに設定しておかないと、deleteでエラーになる時がある。
    char  *s = NULL;
public:
    String();                   // デフォルトコンストラクター
    String(const String &);     // コピーコンストラクター
    String(const char *);       // charの配列を、String化するためのコンストラクター
    String(int);                // intをString化するためのコンストラクター
    ~String();                  // デストラクター
    
    // 代入演算子（=）のオーバーロード
    String &operator = (const String &);
    
    int  length();              // 保持している文字列の長さを返す。
    char *get();                // 保持している文字列のポインタを返す
    
    // Printableで指定されるメンバー関数を実装
    void print();               // 文字列をコンソールへ出力（表示）する。
    String toString();
    
    // 以下はメンバー関数ではない。
    // friend指定することで、privateメンバーにもアクセス可能になる。
    // 「情報の隠蔽」と矛盾するので、不用意にfriend指定してはいけない。
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

/*
 クラス名：Menu
 */
class Menu{
    Output  *out = NULL;
    int  stat;
public:
    Menu();
    
    static const int CONSOLE    = 0;
    static const int FILEOUTPUT = 1;
    static const int EXIT       = 9;
    
    static const int CONTINUE   = 1;
    static const int BREAK      = -1;

    Output &menu();
    
    void cleanup();
    int status();
};

#endif /* mystring_h */
