#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _DATA{
    char  name[20];
    char  addr[40];
}DATA;

int main(){
    int  size;
    char  str[60];
    int  i;
    DATA  data;

    void  *p;
    DATA *dp;
    
    size = sizeof(DATA);
    printf("SIZE : %d\n",size);
    
    printf("size of str : %d\n",(int)sizeof(str));
    
    for(i=0;i<60;i++){
        str[i] = 0x00;
    }
    
    str[0] = 'A';
    str[1] = 'p';
    str[2] = 'p';
    str[3] = 'l';
    str[4] = 'e';
    
    str[20] = 'B';
    str[21] = 'a';
    str[22] = 'n';
    str[23] = 'a';
    str[24] = 'n';
    str[25] = 'a';

    strcpy((char *)&data,str);
    printf("%s , %s\n",data.name,data.addr);
    
    memcpy(&data,str,sizeof(str));
    printf("%s , %s\n",data.name,data.addr);
    
    p = malloc(sizeof(DATA));
    memcpy(p,str,sizeof(str));
    
    dp = (DATA *)p;
    printf("%s - %s\n",dp->name,dp->addr);

    free(p);
    
    return 0;
}
