//
//  mylib.h
//  Ex30
//
//  Created by 瀬川健児 on 2020/05/26.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#ifndef mylib_h
#define mylib_h

class String;

class String{
    char  *s = NULL;
public:
    String();
    String(const String &);
    String(const char *);
    ~String();
    
    String &operator = (const String &);
    void print();
    int length();
};

#endif /* mylib_h */
