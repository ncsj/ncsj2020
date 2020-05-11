#include <stdio.h>

typedef  struct  _DATA{
    char    name[20];
    int     x;
    int     y;
}DATA;

void printData(DATA *p){
    printf("%s : %d,%d\n",p->name,p->x,p->y);
}

void setData(DATA *p){
    printf("name : ");
    scanf("%s",p->name);
    
    printf("x : ");
    scanf("%d",&p->x);
    
    printf("y : ");
    scanf("%d",&p->y);
}

void  readData(char *p){
    FILE  *fp;
    DATA  data;
    long   rtc;
    
    fp = fopen(p,"rb");
    if(fp == NULL){
        printf("FILE OPEN ERROR : %s\n",p);
    }
    else{
        rtc = fread(&data,sizeof(DATA),1,fp);
        if(rtc > 0){
            printData(&data);
        }
        
        fclose(fp);
    }
}

int plus(int x,int y){
    int  rtc;
    rtc = x + y;
    
    printf("%d + %d = %d\n",x,y,rtc);
    
    return rtc;
}

int main(){
    DATA    data;
    FILE    *fp;
    char  fname[20];
    
    setData(&data);
    printData(&data);
    
    fp = fopen(data.name,"w+b");
    if(fp != NULL){
        fwrite(&data,sizeof(DATA),1,fp);
        fclose(fp);
    }
    
    printf("FILE NAME : ");
    scanf("%s",fname);
    
    readData(fname);

    return 0;
}
