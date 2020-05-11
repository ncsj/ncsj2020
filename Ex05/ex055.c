#include <stdio.h>

int main(){
    int  x;
    char s[20];
    char str[100];
    
    printf("x : ");
    scanf("%d",&x);
    
    printf("s : ");
    scanf("%s",s);
    
    sprintf(str,"x : %d - s : %s", x, s);
    
    printf("str : %s\n",str);
    
    return 0;
}
