#include <stdio.h>

int  slength(const char *s){
    int  n = 0;
    int  loop;
    
    loop = 1;
    while(loop == 1){
        if(*(s+n) > 0x00){
            n++;
        }
        else{
            loop = 0;
        }
    }
    return n;
}

void scopy(char *s,const char *t){
    int  count = 0;
    
    while(*(t+count) > 0x00){
        *(s+count) = *(t+count);
        count++;
    }
    
    *(s+count) = 0x00;
}

int main(){
    char  str[20];
    char  s[20];
    int   count = 0;
    
    str[0] = 'B';
    str[1] = 'a';
    str[2] = 'n';
    str[3] = 'a';
    str[4] = 'n';
    str[5] = 'a';
    str[6] = 0x00;

    count = slength( str );
    
    printf("str : %s\n",str);
    printf("length : %d\n",count);
    
    scopy(s,str);
    
    printf("s : %s\n",s);
    printf("length : %d\n",slength(s));
    
    return 0;
}
