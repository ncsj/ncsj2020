#include <stdio.h>

int slen(const char *s){
    int count = 0;
    while(*(s+count) != 0x00){
        count++;
    }
    return count;
}

int power(int x,int y){
    int r = 1;
    int i;
    
    for(i=0;i<y;i++){
        r = r * x;
    }
    
    return r;
}

int StoI(const char *s){
    int  sum = 0;
    int  n = 0;
    int  i;
    int  len;
    char c;
    int  x;
    
    len = slen(s);
    for(i=0;i<len;i++){
        c = *(s+i);
        n = c - '0';
        printf("[%d] - '%c'(%d)\n",i,c,n);
        
        x = power(10,len-(i+1));
        n = n * x;
        sum = sum + n;
    }
    
    return sum;
}


int main(){
    char  snum[10];
    int   num;
    
    sprintf(snum,"12345");
    
    num = StoI(snum);
    
    printf("NUMBER : %d\n",num);
    
    return 0;
}
