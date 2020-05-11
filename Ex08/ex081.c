#include <stdio.h>

void  f(void);
int  plus(int,int);
void scopy(char *,const char *);

int main(){
    int  result;
    int  x;
    int  y;
    char  s1[128];
    char  s2[128];
    
    f();
    
    x = 100;
    y = 23;
    result = plus(100,23);
    
    printf("%d + %d = %d\n",x,y,result);
    
    printf("----------\n");
    
    printf("S1 : ");
    scanf("%s",s1);
    
    scopy(s2,s1);
    
    printf("%s : %s\n",s1,s2);
    
    return 0;
}

void scopy(char *s1,const char *s2){
    int  i=0;
    
    while(*(s2+i) != 0x00){
        *(s1+i) = *(s2+i);
        i++;
    }
    
    *(s1+i) = 0x00;
}

void  f(){
    printf("Hello!\n");
}

int plus(int x,int y){
    return x + y;
}
