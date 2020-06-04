//
//  menu.h
//  STEPs
//
//  Created by 瀬川健児 on 2020/06/04.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <string.h>

/* メニュークラスに関連するクラスの宣言               */
class String;       /* Stringクラスの宣言        */
class Menu;         /* Menuクラスの宣言          */
class MenuItem;     /* MenuItemクラスの宣言      */

/*
 Stringクラスの定義
 文字列をサポートするためのクラス
 */
class String{
    char *s = NULL;
public:
    String();
    String(const String &);
    String(const char *);
    ~String();
    
    String  &operator = (const String &);
    char    *get();
    int     length();
    
    friend String operator + (const String &,const String &);
};

/*
 Menuクラスの定義
 アプリケーションで利用するメニューを実現するクラス
 文字列を含むメニューアイテム（MenuItem）を追加することで、
 メニューを構成することができる。
 */
class Menu{
    MenuItem  *item = NULL;
public:
    ~Menu();                    // デストラクター
    void add(MenuItem *);       // メニューアイテムを追加する
    void add(const String &);   // メニューアイテムを追加する
    int  show();                // メニューを表示し、選択した番号を返す
};

/*
 MenuItemクラスの定義
 メニュー（Menu）で利用するメニューアイテム（MenuItem）を実現するクラス
 MenuItemは、Menuクラスでのみ利用さる。
 実際には、文字列（String）をリストで保持するための
 データ構造およびアルゴリズムを実装している。
 */
class MenuItem{
    String title;
    MenuItem  *np = NULL;
public:
    MenuItem(const String &);   // コンストラクター
    MenuItem  *next();          // 次のメニューアイテムを取り出す
    void next(MenuItem *);      // 次のメニューアイテムを設定する
    
    String getTitle();          // アイテムが保持しているタイトルを取り出す
};


#endif /* menu_h */
