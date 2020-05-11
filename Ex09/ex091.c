#include <stdio.h>

typedef struct _DATA DATA;

struct _DATA{
    char  name[20];
    char  addr[40];
    int   age;
    
    DATA  *next;
};

void print(DATA *p){
    printf("%s[%d] - %s\n",p->name,p->age,p->addr);
}

void listup(DATA *p){
    int  i = 0;
    
    while(p != NULL){
        printf("[%d]",i);
        print( p );
        
        p = p->next;
        i++;
    }
}

int count(DATA *p){
    int n = 0;
    while(p != NULL){
        n++;
        p = p->next;
    }
    return n;
}

void add(DATA *p,DATA *e){
    while(p->next != NULL){
        p = p->next;
    }
    p->next = e;
}

void insert(DATA *p,DATA *e,int n){
    int  count = 0;
    
    while(count < n){
        p = p->next;
        count++;
    }
    
    e->next = p->next;
    p->next = e;
}

void removeData(int ti,DATA *p){
    int  i;
    DATA  *prev = NULL;
    
    for(i=0;i<ti;i++){
        prev = p;
        p = p->next;
    }
    
    prev->next = p->next;
}

int main(){
    DATA  d1;
    DATA  d2;
    DATA  d3;
    int  n = 0;
    
    DATA  d4;
    
    DATA  d5;
    DATA  d6;
    DATA  d7;
    
    sprintf(d1.name,"伊藤博文");
    sprintf(d1.addr,"山口県");
    d1.age  =   22;

    sprintf(d2.name,"黒田清隆");
    sprintf(d2.addr,"鹿児島県");
    d2.age  =   33;

    sprintf(d3.name,"大隈重信");
    sprintf(d3.addr,"佐賀県");
    d3.age  =   44;

    sprintf(d4.name,"福沢諭吉");
    sprintf(d4.addr,"大阪府");
    d4.age  =   55;
    d4.next = NULL;

    d1.next = &d2;
    d2.next = &d3;
    d3.next = NULL;
    
    listup( &d1 );
    
    n = count( &d1 );
    printf("COUNT : %d\n",n);

    printf("----------\n");
    
    add(&d1,&d4);
    listup(&d1);
    n = count( &d1 );
    printf("COUNT : %d\n",n);

    sprintf(d5.name,"西郷隆盛");
    sprintf(d5.addr,"鹿児島県");
    d5.age  =   66;
    d5.next = NULL;

    sprintf(d6.name,"徳川慶喜");
    sprintf(d6.addr,"茨城県");
    d6.age  =   77;
    d6.next = NULL;

    sprintf(d7.name,"坂本龍馬");
    sprintf(d7.addr,"高知県");
    d7.age  =   88;
    d7.next = NULL;
    
    insert(&d1,&d5,0);
    insert(&d1,&d6,2);
    insert(&d1,&d7,4);
    
    listup( &d1 );

    removeData(1,&d1);
    
    listup(&d1);

    return 0;
}
