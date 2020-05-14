#include <stdio.h>
#include <stdlib.h>

#define LF      0x0a

typedef struct _LINE  LINE;
struct _LINE{
    char  s[256];
    LINE  *next;
};

typedef struct _COL COL;
struct _COL{
    char data[64];
};

int countColumn(LINE *p){
    int count = 1;
    int i=0;
    while(p->s[i] != 0x00){
        switch(p->s[i]){
            case ',':
                count++;
                break;
            default:
                break;
        }
        i++;
    }
    return count;
}

int slen(const char *s){
    int len = 0;
    while(*(s+len) != 0x00){
        len++;
    }
    return len;
}

COL *toColumn(LINE *p){
    COL *cols = NULL;
    int count;
    int i;
    int ii = 0;
    int n  = 0;
    int len;
    
    count = countColumn(p);
    cols = (COL *)malloc(sizeof(COL)*count);
    
    len = slen( p->s );
    
    for(i=0;i<len;i++){
        switch( p->s[i] ){
            case ',':
                (cols+n)->data[ii] = 0x00;
                ii = 0;
                n++;
                break;
            default:
                (cols+n)->data[ii] = p->s[i];
                ii++;
                break;
        }
    }
    (cols+n)->data[ii] = 0x00;

    
    return cols;
}

int main(){
    FILE  *fp;
    const char *fname = "/Users/segawakenji/Desktop/Ex16/Ex16/fruits.csv";
    int  c;
    int  loop = 1;
    int  count = 0;
    int  index = 0;
    int  i;
    int  ii;
    
    int sums[3];
    
    LINE  *bp = NULL;
    LINE  *p  = NULL;
    LINE  *prev = NULL;
    LINE  *next = NULL;
    
    COL *cp = NULL;
    int ccount = 0;
    
    for(i=0;i<3;i++){
        sums[i] = 0;
    }
    
    bp = (LINE *)malloc(sizeof(LINE));
    p = bp;

    fp = fopen(fname,"rt");
    if(fp != NULL){
        while(loop == 1){
            c = fgetc(fp);
            switch( c ){
                case EOF:
                    loop = 0;
                    p->s[index] = 0x00;
                    break;
                case LF:
                    count++;
                    p->s[index] = 0x00;
                    
                    if(prev != NULL){
                        prev->next = p;
                    }
                    prev = p;
                    index = 0;
                    
                    p = (LINE *)malloc(sizeof(LINE));
                    /* printf("\n"); */
                    break;
                default:
                    /* printf("%c",(char)c); */
                    p->s[index] = (char)c;
                    index++;
                    break;
            }
        }
        
        fclose(fp);
    }
    
    i = 0;
    p = bp;
    while(p!=NULL){
        printf("[%d] ",i+1);
        
        cp = toColumn(p);
        ccount = countColumn(p);
        for(ii=0;ii<ccount;ii++){
            printf(" [%s]",(cp+ii)->data);
            
            if(ii>0){
                sums[ii-1] = sums[ii-1] + atoi((cp+ii)->data);
            }
        }
        printf("\n");
        
        
        p = p->next;
        i++;
    }
    
    printf("[%d]  [SUM]",count+1);
    for(i=0;i<3;i++){
        printf(" [%d]",sums[i]);
    }
    printf("\n");
    
    p = bp;
    while(p != NULL){
        next = p->next;
        free(p);
        p = next;
    }
    
    return 0;
}
