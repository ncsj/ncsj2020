#include <stdio.h>
#include <stdlib.h>

typedef struct _NUMBER NUMBER;
struct _NUMBER{
    char  name[20];
    int  n;
    NUMBER *next;
};

/*
 int compare(const NUMBER *,const NUMBER *);
 NUMBER構造体の中で保持している値（int n）の大小比較を行う。
 比較した結果を、int型の値で返す。
 
 戻り値    -1      引数１(p1)が小さい
          0       引数１(p1)と引数２(p2)とが同じ
          1       引数２(p2)が小さい

引数     const NUMBER *p1    引数１
        const NUMBER *p2    引数２
 */
int  compare(const NUMBER *p1,const NUMBER *p2){
    int rtc = 0;
    
    if(p1->n < p2->n){
        rtc = -1;
    }
    else if(p1->n > p2->n){
        rtc = 1;
    }
    
    return rtc;
}

/*
 int  order(const NUMBER *,const NUMBER *);
 最初に指定するNUMBER構造体のリストの中で、
 次に指定するNUMBER構造体のデータが
 何番目に位置するのか、その順位を0からはじまる
 整数値として返す。
 
 なお、より順位の若いデータは、その中で保持している
 値が小さいものとする。
 */
int order(const NUMBER *numbers,const NUMBER *p){
    int  count = 0;
    const NUMBER *cur = numbers;
    
    while(cur != NULL){
        if(cur->n < p->n){
            count++;
        }
        cur = cur->next;
    }
    return count;
}

void listup(const NUMBER *p){
    int i = 0;
    while(p != NULL){
        printf("[%d] %s %d\n",(i+1),p->name,p->n);
        p = p->next;
        i++;
    }
}

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

NUMBER *sort(NUMBER *p){
    NUMBER **buff;      /* NUMBER  *buff[]  */
    NUMBER *cur = p;    /* NUMBERのデータ１つを示すためのポインター */
    NUMBER *bp = NULL;  /* ソートしたリストの先頭を示すポインター */
    int  size;
    int  i;
    int  n;
    
    size = count( p );
    buff = (NUMBER **)malloc(sizeof(NUMBER*)*size);
    cur = p;
    while(cur != NULL){
        n = order(p,cur);
        *(buff+n) = cur;    /* buff[n] = cur */
        cur = cur->next;
    }
    
    for(i=0;i<size-1;i++){
        cur = *(buff+i);
        if(bp == NULL){
            bp = cur;
        }
        cur->next = *(buff+i+1);
        cur = cur->next;
    }
    
    cur->next = NULL;
    
    free(buff);
    return bp;
}

NUMBER *loadNumbers(){
    NUMBER *p = NULL;
    NUMBER *bp = NULL;
    NUMBER *prev = NULL;
    
    FILE *fp;
    long  rtc;
    int   loop = 1;
    
    NUMBER  number;
    
    fp = fopen("numbers.data","rb");
    if(fp != NULL){
        printf("----- FILE LOAD ... -----\n");
        while(loop == 1){
            rtc = fread(&number,sizeof(NUMBER),1L,fp);
            if(rtc < 1L){
                loop = 0;
            }
            else{
                /* printf("%s : %d\n",number.name, number.n); */
                
                p = (NUMBER *)malloc(sizeof(NUMBER));
                
                p->n = number.n;
                sprintf(p->name,"%s",number.name);
                p->next = NULL;
                
                if(bp == NULL){
                    bp = p;
                }
                
                if(prev != NULL){
                    prev->next = p;
                }
                
                prev = p;
            }
        }
        fclose(fp);
    }
    else{
        printf("FILE OPEN ERROR\n");
        printf("load numbers ...\n");
    }
    
    
    return bp;
}

void saveNumbers(const NUMBER *p){
    FILE  *fp;
    int  rtc;
    
    fp = fopen("numbers.data","w+b");
    if(fp != NULL){
        while(p != NULL){
            rtc = (int)fwrite(p,sizeof(NUMBER),1L,fp);
            if(rtc < 1){
                p = NULL;
                printf("ERROR : rtc < 0\n");
            }
            else{
                p = p->next;
            }
        }
        
        fclose(fp);
    }
    else{
        printf("FILE OPEN ERROR\n");
    }
}

int main(){
    NUMBER *bp = NULL;
    NUMBER *last;
    NUMBER *next;
    NUMBER *p;
    int array[] = {10,2,30,4,50,6,70,80,9,100};
    char *names[] = {"America","Bragil","Canada","Datch","England","France","German","Holand","Ireland","Japan"};
    int sum;
    int ave;
    int i;
    
    for(i=0;i<10;i++){
        p = (NUMBER *)malloc(sizeof(NUMBER));
        
        p->n = array[i];
        sprintf(p->name,"%s",names[i]);
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
    
    /*
     ここでソート（sort）してください。
     */
    bp = sort(bp);
    listup(bp);
    
    sum = summary(bp);
    ave = average(bp);
    
    printf("sum : %d\n",sum);
    printf("ave : %d\n",ave);

    ave = average2(bp);
    printf("ave2 : %d\n",ave);
    
    
    saveNumbers( bp );
    
    p = bp;
    while(p != NULL){
        next = p->next;
        
        free(p);
        p = next;
    }
    
    p = loadNumbers();
    listup(p);
    
    while(p != NULL){
        next = p->next;
        
        free(p);
        p = next;
    }
    
    return 0;
}
