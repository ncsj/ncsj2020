#include <stdio.h>

void splus(char *s,const char *s1,const char *s2){
    int  index = 0;
    int  index1 = 0;
    int  index2 = 0;
    
    while(*(s1+index1)!=0x00){
        *(s+index) = *(s1+index1);
        
        index++;
        index1++;
    }
    
    while(*(s2+index2)!=0x00){
        *(s+index) = *(s2+index2);
        
        index++;
        index2++;
    }
    
    *(s+index) = 0x00;
}


int main(){
    const char *p = "Apple";
    const char *q = "Banana";
    char  s[128];
    
    printf("p : %s\n", p);
    printf("%s%s\n",p,q);
    
    splus(s,p,q);           /* sの内容が、"AppleBanana"となるように*/
    printf("s : %s\n",s);   /* splus()関数を作成してください。*/
    
    return 0;
}
