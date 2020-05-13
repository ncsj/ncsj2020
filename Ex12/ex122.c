#include <stdio.h>

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

int search(const char *s,const char *word){
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
                    
                    i = i + lb;
                    clearBuffer(t,20);
                }
            }
        }
    }
    
    
    return count;
}

int main(){
    const char *text = "This is a pen. The pen is black.pen";
    char word[20];
    int  count;
    
    sprintf(word,"pen");
    
    count = search(text,word);
    if(count < 0){
        printf("ERROR\n");
    }
    else{
        printf("%s : %d\n",word,count);
    }
    
    return 0;
}
