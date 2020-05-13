#include <stdio.h>
#include <time.h>

void printMonth(int mon){
    int months[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    char *wdays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    int  i;
    int  end;
    int  count = 0;
    
    struct tm target;
    
    target.tm_year = 120;   /* 2020 */
    target.tm_mon  = mon - 1;
    target.tm_mday = 1;
    target.tm_hour = 0;
    target.tm_min  = 0;
    target.tm_sec  = 0;
    
    mktime(&target);
    
    end = months[mon-1];
    
    count = target.tm_wday;
    
    for(i=0;i<7;i++){
        printf("%s",wdays[i]);
    }
    printf("\n");

    for(i=0;i<count;i++){
        printf("   ");      /* 半角の空白（スペース）を３つ出力 */
    }
    
    for(i=0;i<end;i++){
        printf("%3d",(i+1));
        
        count++;
        if(count == 7){
            printf("\n");
            count = 0;
        }
    }
    
    
    printf("\n");
}

int main(){
    int  month;
    
    printf("MONTH[1-12] : ");
    scanf("%d", &month);
    
    printMonth(month);
    
    return 0;
}
