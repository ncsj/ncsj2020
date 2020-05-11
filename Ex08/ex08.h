//
//  ex08.h
//  Ex08
//
//  Created by 瀬川健児 on 2020/04/22.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#ifndef ex08_h
#define ex08_h

typedef  struct _DATA  DATA;

void  f(void);
int  plus(int,int);
void scopy(char *,const char *);
void set(DATA *);
void print(DATA *);

struct _DATA{
    int  x;
    int  y;
};


#endif /* ex08_h */
