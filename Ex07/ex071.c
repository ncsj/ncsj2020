#include <stdio.h>

int  slen(char *p){
    int n = 0;
    
    while(*(p+n) != 0x00){
        n++;
    }
    
    return n;
}

void scopy(char *s1,char *s2){
    int  n = 0;
    
    while(*(s2+n) != 0x00){
        *(s1+n) = *(s2+n);
        n++;
    }
    *(s1+n) = 0x00;
}

int main(){
    char  s[128];
    char  s2[128];
    int  len = 0;
    
    s[0] = 'A';
    s[1] = 'p';
    s[2] = 'p';
    s[3] = 'l';
    s[4] = 'e';
    s[5] = 0x00;
    
    printf("s : %s\n", s);
    
    len = slen( s );
    printf("len : %d\n",len);
    
    scopy(s2,s);
    printf("s2 : %s\n",s2);
    
    return 0;
}
