#include <stdio.h>

int slen(const char *s){
    int len = 0;
    
    while(*(s+len) != 0x00){
        len++;
    }
    
    return len;
}

int compare(const char *s1,const char *s2){
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
            break;
        }
        else if(*(s1+i) > *(s2+i)){
            rtc = 1;
            break;
        }
    }
    
    if(rtc == 0 && len1 != len2){
        if(len1 > len2){
            rtc = 1;
        }
        else if(len1 < len2){
            rtc = -1;
        }
    }
    
    return rtc;
}

int order(const char *p[], const char *s){
    int  n = 0;
    int  i;
    int  rtc;
    
    for(i=0;i<6;i++){
        rtc = compare(*(p+i),s);
        if(rtc < 0){
            n++;
        }
    }

    return n;
}

void sort(char *target[],const char *src[]){
    int  i;
    int  n;
    
    for(i=0;i<6;i++){
        n = order(src,*(src+i));
        
        *(target+n) = *(src+i);
    }
}

int  main(){
    char    s1[10];
    char    s2[10];
    int     rtc;
    
    const char *words[] = {"Banana","Candy","Apple","Fruits","Egg","Donuts"};
    char  *swords[6];
    int  n;
    int  i;
    
    printf("INPUT S1 : ");
    scanf("%s",s1);
    
    printf("INPUT S2 : ");
    scanf("%s",s2);
    
    rtc = compare(s1,s2);
    if(rtc == 0){
        printf("%s = %s\n", s1, s2);
    }
    else if(rtc < 0){
        printf("%s < %s\n", s1, s2);
    }
    else if(rtc > 0){
        printf("%s > %s\n", s1, s2);
    }
    
    n = order(words,words[0]);
    printf("%s : %d\n",words[0],n+1);
    
    sort(swords,words);
    
    for(i=0;i<6;i++){
        printf("[%d] : %s\n",i,*(swords+i));
    }
    
    return 0;
}
