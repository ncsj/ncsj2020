#include <stdio.h>
#include <string.h>

int main(){
    char  s[20];
    char  s2[20];
    int  count;
    
    printf("s[20] : ");
    scanf("%s",s);
    
    count = strlen(s);
    
    printf("%s : %d\n",s,count);
    
    strcpy(s2,s);
    printf("s2 : %s\n",s2);
    
    return 0;
}
