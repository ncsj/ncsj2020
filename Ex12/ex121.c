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


int main(){
    char    s1[20];
    char    s2[20];
    int     rtc;
    
    printf("INPUT [s1] : ");
    scanf("%s",s1);
    
    printf("INPUT [s2] : ");
    scanf("%s",s2);
    
    printf("%s : %s\n",s1,s2);
    
    rtc = scomp(s1,s2);
    if(rtc < 0){
        printf("%s < %s\n",s1,s2);
    }
    else if(rtc == 0){
        printf("%s == %s\n",s1,s2);
    }
    else if(rtc > 0){
        printf("%s > %s\n",s1,s2);
    }
    
    return 0;
}
