#include <stdio.h>
#include <stdlib.h>

typedef  struct _STATION  STATION;
struct _STATION{
    int     id;
    char    name[20];
    STATION  *next;
};

void listup(STATION *p){
    while(p != NULL){
        printf("[%d] %s\n",p->id,p->name);
        p = p->next;
    }
}

void  print(STATION **p){
    printf("[%d] %s\n",(*p)->id,(*p)->name);
    
     *p = (STATION *)malloc(sizeof(STATION));

    (*p)->id = 0;
    sprintf((*p)->name,"SHINJUKU");
    (*p)->next = NULL;
}

void removeStation(STATION **p,int index){
    int i = 0;
    
    while((*(p+i)) != NULL){
        if(index == i){
            (*(p+i)) = (*(p+i))->next;
            break;
        }
        
        i++;
    }
}

int main(){
    STATION  st1;
    STATION  st2;
    STATION  st3;
    STATION  st4;
    
    STATION *p;
    STATION *p2;

    st1.id = 1;
    sprintf(st1.name,"AKABANE");
    st1.next = &st2;
    
    st2.id = 2;
    sprintf(st2.name,"JUJO");
    st2.next = &st3;
    
    st3.id = 3;
    sprintf(st3.name,"ITABASHI");
    st3.next = &st4;
    
    st4.id = 4;
    sprintf(st4.name,"IKEBUKURO");
    st4.next = NULL;
    
    p = &st1;
    
    listup( p );
    
    printf("----------\n");
    removeStation(&p,0);
    
    listup( p );

    /**
    p = &st1;
    p2 = &st2;
    
    p = p2;
    printf("[%d] %s\n",p->id,p->name);

    print(&p);
    
    printf("[%d] %s\n",p->id,p->name);
    
    free( p );
    **/
    
    return 0;
}
