#include <stdio.h>

typedef  struct _PERSON{
    char  name[21];
    char  addr[41];
    char  tel[14];
    int   age;
}PERSON;

void initPersons(PERSON *p){
    int  i;
    for(i=0;i<10;i++){
        (p+i)->age = -1;
    }
}

void printPerson(PERSON *p){
    printf("%s[%d] : %s : %s\n", p->name,p->age,p->addr,p->tel);
}

void printPersons(PERSON *p){
    int  i;
    for(i=0;i<10;i++){
        if((p+i)->age >= 0){
            printPerson((p+i));
        }
    }
}

void setPerson(PERSON *p){
    printf("name : ");
    scanf("%s",p->name);
    
    printf("addr : ");
    scanf("%s",p->addr);
    
    printf("tel : ");
    scanf("%s",p->tel);
    
    printf("age : ");
    scanf("%d",&p->age);
}

void savePersons(PERSON *p){
    FILE  *fp;
    long   rtc;
    
    int  loop = 1;
    int  count = 0;
    
    fp = fopen("persons.data","wb");
    if(fp == NULL){
        printf("FILE OPEN ERROR!\n");
    }
    else{
        while(loop == 1){
            if(p->age > 0){
                rtc = fwrite(p,sizeof(PERSON),1,fp);
                if(rtc < 1){
                    printf("FILE WRITE ERROR\n");
                    loop = 0;
                }
                else{
                    p++;
                    count++;
                }
            }
            else{
                loop = 0;
            }
        }
        fclose(fp);
        
        printf("WRITE DATA : %d\n",count);
    }
}

void loadPersons(PERSON *p){
    FILE *fp;
    int  loop = 1;
    long  rtc;
    int  count = 0;
    
    fp = fopen("persons.data","rb");
    if(fp != NULL){
        while(loop == 1){
            rtc = fread(p,sizeof(PERSON),1,fp);
            if(rtc < 1){
                loop = 0;
            }
            else{
                p++;
                count++;
            }
        }
        fclose(fp);
        
        printf("READ COUNT : %d\n",count);
    }
    else{
        printf("FILE OPEN ERROR\n");
    }
}

int  main(){
    PERSON  persons[10];
    PERSON  plist[10];
    int     i;
    
    initPersons(persons);
    initPersons(plist);
    
    for(i=0;i<3;i++){
        setPerson(&persons[i]);
    }
    
    printPersons(persons);
    savePersons(persons);
    
    printf("----------------\n");
    
    loadPersons(plist);
    printPersons(plist);
    
    return 0;
}
