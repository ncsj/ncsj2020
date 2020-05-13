//
//  ex111a.c
//  Ex11
//
//  Created by 瀬川健児 on 2020/04/27.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

void  f1(){
    printf("f1()\n");
}

void f2(){
    printf("f2()\n");
}
void f3(){
    printf("f3()\n");
}
void f4(){
    printf("f4()\n");
}
void f5(){
    printf("f5()\n");
}
void f6(){
    printf("f6()\n");
}
void f7(){
    printf("f7()\n");
}
void f8(){
    printf("f8()\n");
}
void f9(){
    printf("f9()\n");
}
void f10(){
    printf("f10()\n");
}

typedef struct _FUNC  FUNC;
struct _FUNC{
    char  title[128];
    void  (*f)();
    FUNC  *next;
};

void  exec(FUNC *p){
    printf("START");
    while(p != NULL){
        printf("%s\n",p->title);
        p->f();
        p = p->next;
    }
    printf("FINISH\n");
}

int main(){
    void  (*vp)();
    void  (*vps[10])();
    int  i;
    
    FUNC  func1;
    FUNC  func2;
    FUNC  func3;
    FUNC  func4;
    FUNC  func5;
    
    
    vps[0] = f1;
    vps[1] = f2;
    vps[2] = f3;
    vps[3] = f4;
    vps[4] = f5;
    vps[5] = f6;
    vps[6] = f7;
    vps[7] = f8;
    vps[8] = f9;
    vps[9] = f10;
    
    for(i=0;i<10;i++){
        vps[i]();
    }
    
    printf("INPUT NUMBER[1-10] : ");
    scanf("%d",&i);
    
    vps[i-1]();
    
    printf("------------------\n");
    
    sprintf(func1.title,"FUNC-1");
    func1.f = f1;
    func1.next = &func2;
    
    sprintf(func2.title,"FUNC-2");
    func2.f = f1;
    func2.next = &func3;
    
    sprintf(func3.title,"FUNC-3");
    func3.f = f3;
    func3.next = &func4;
    
    sprintf(func4.title,"FUNC-4");
    func4.f = f4;
    func4.next = &func5;
    
    sprintf(func5.title,"FUNC-5");
    func5.f = f5;
    func5.next = NULL;
    
    exec(&func1);

    return 0;
}
