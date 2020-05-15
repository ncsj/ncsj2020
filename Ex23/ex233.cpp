//
//  ex233.cpp
//  Ex23
//
//  Created by 瀬川健児 on 2020/05/16.
//  Copyright © 2020 瀬川健児. All rights reserved.
//  アップロード前に、プロジェクトが壊れてしまいました。
//  授業でやった内容を再現したつもりですが、
//  細かいところは相違があると思います。

#include <stdio.h>

int sum(const int *p,int size){
    int n = 0;
    for(int i=0;i<size;i++){
        n = n + *(p+i);
    }
    return n;
}

int main(){
    int *p;
    
    p = new int;
    
    printf("INPUT NUMBER : ");
    scanf("%d",p);
    
    delete p;
    
    int size;
    printf("INPUT SIZE : ");
    scanf("%d",&size);
    
    p = new int [size];
    for(int i=0;i<size;i++){
        *(p+i) = i + 1;
    }
    
    printf("SUM : %d\n",sum(p,size));
    delete [] p;
}

