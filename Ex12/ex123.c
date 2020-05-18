#include <stdio.h>

typedef struct _RANGE RANGE;
struct _RANGE{
    int  begin;
    int  end;
};

void printRange(RANGE *p){
    printf("%d - %d\n",p->begin,p->end);
}

int slen(const char *s){
    int len = 0;
    
    while(*(s+len)!=0x00){
        len++;
    }
    
    return len;
}


int scomp(const char *s1,const char *s2){
    int  rtc = 0;
    int  len1;
    int  len2;
    int  len;
    int  i;
    
    len1 = slen(s1);
    len2 = slen(s2);
    if(len1 <= len2){
        len = len1;
    }
    else{
        len = len2;
    }
    
    for(i=0;i<len;i++){
        if(*(s1+i) < *(s2+i)){
            rtc = -1;
        }
        else if(*(s1+i) > *(s2+i)){
            rtc = 1;
        }
    }
    
    if((rtc==0) && (len1 != len2)){
        if(len1 < len2){
            rtc = -1;
        }
        else if(len1 > len2){
            rtc = 1;
        }
    }
    
    
    return rtc;
}

void clearBuffer(char *buff,int size){
    int  i;
    
    for(i=0;i<size;i++){
        *(buff + i) = 0x00;
    }
}

void scopy(char *s,const char *t){
    int  i;
    int len;
    
    len = slen(t);
    
    for(i=0;i<len;i++){
        *(s+i) = *(t+i);
    }
    
    *(s+i) = 0x00;
}

int search(const char *s,const char *word,RANGE *p){
    int count = 0;
    int rtc;
    int  la;
    int  lb;
    int  i;
    int  ii;
    
    char t[20];
    
    la = slen(s);
    lb = slen(word);
    
    if(la <= lb){
        count = -1;
    }
    else{
        for(i=0;i<=la-lb;i++){
            if(*(s+i)==*(word+0)){
                
                for(ii=0;ii<lb;ii++){
                    t[ii] = *(s+i+ii);
                }
                t[ii] = 0x00;
                
                rtc = scomp(t,word);
                if(rtc == 0){
                    printf("[%s] is found.\n",t);
                    count++;
                    
                    p->begin    = i;
                    p->end      = i+lb-1;
                    
                    i = i + lb;
                    clearBuffer(t,20);
                }
            }
        }
    }
    
    
    return count;
}

void replace(char *s,const char *s1,const char *s2){
    int  i;
    int  ii;
    int  ti = 0;
    int  len;
    char  c;
    RANGE  range;
    int  count;
    int  offset = 0;
    
    char  t[128];       // buffer for work.
    
    len = slen( s );

    count = search(s,s1,&range);
    if(count > 0){
        printRange(&range);
        for(i=0;i<range.begin;i++){
            c = *(s+i);
            printf("%c",c);
            
            t[ti] = c;
            ti++;
        }
        
        for(ii=0;ii<slen(s2);ii++){
            c = *(s2+ii);
            printf("%c",c);
            
            t[ti] = c;
            ti++;
        }
        
        for(i=range.end+1;i<len;i++){
            c = *(s+i);
            printf("%c",c);
            
            t[ti] = c;
            ti++;
        }
        
        t[ti] = 0x00;
        scopy(s,t);
    }

    
    
    printf("\n");
}

int main(){
    char text[128];
    char s1[10];
    char s2[10];
        
    sprintf(text,"It is fine,today.");
    
    printf("TEXT : %s\n",text);
    
    printf("s1[10] : ");
    scanf("%s",s1);

    printf("s2[10] : ");
    scanf("%s",s2);
    
    replace(text,s1,s2);
    
    printf("TEXT : %s\n",text);

    return 0;
}
