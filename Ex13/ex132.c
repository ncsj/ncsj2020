#include <stdio.h>
#include <time.h>

int main(){
    time_t now;
    time_t st;
    time_t t;
    unsigned  long  offset;
    
    struct tm *stp;
    struct tm *wtp;
    
    printf("SET OFFSET : ");
    scanf("%ld",&offset);
    
    now = time(NULL);
    st = now;

    stp = localtime(&st);
    printf("%02d:%02d:%02d\n",stp->tm_hour,stp->tm_min,stp->tm_sec);

    t = now + offset;
    while(now < t){
        now = time(NULL);
    }
    
    
    printf("WAKE UP!\n");
    
    wtp = localtime(&t);
    printf("%02d:%02d:%02d\n",wtp->tm_hour,wtp->tm_min,wtp->tm_sec);

    return 0;
}
