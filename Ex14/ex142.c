#include <stdio.h>
#include <stdlib.h>

typedef struct _NUMBER NUMBER;
struct _NUMBER{
    int  n;
    NUMBER *next;
};

int summary(const NUMBER *p){
    int  sum = 0;
    while(p != NULL){
        sum = sum + p->n;
        p = p->next;
    }
    return sum;
}

int count(const NUMBER *p){
    int  c = 0;
    while(p != NULL){
        c++;
        p = p->next;
    }
    return c;
}

int average2(const NUMBER *p){
    int ave;
    ave = summary(p) / count(p);
    return ave;
}

int average(const NUMBER *p){
    int  sum = 0;
    int  count = 0;
    int  ave;
    while(p != NULL){
        sum = sum + p->n;
        p = p->next;
        
        count++;
    }
    ave = sum / count;
    return ave;
}

int main(){
    NUMBER *bp = NULL;
    NUMBER *last;
    NUMBER *next;
    NUMBER *p;
    int array[] = {10,2,30,4,50,6,70,80,9,100,110,-100,-10,-1,0};
    int sum;
    int ave;
    int i;
    
    for(i=0;i<15;i++){
        p = (NUMBER *)malloc(sizeof(NUMBER));
        p->n = array[i];
        p->next = NULL;
        
        if(bp == NULL){
            bp = p;
        }
        else{
            last = bp;
            while(last->next != NULL){
                last = last->next;
            }
            
            last->next = p;
        }
    }
    
    sum = summary(bp);
    ave = average(bp);
    
    printf("sum : %d\n",sum);
    printf("ave : %d\n",ave);

    ave = average2(bp);
    printf("ave2 : %d\n",ave);
    
    
    p = bp;
    while(p != NULL){
        next = p->next;
        
        free(p);
        p = next;
    }
    
    return 0;
}
