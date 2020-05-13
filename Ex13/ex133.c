#include <stdio.h>
#include <time.h>


int main(){
    struct tm mytime;
    time_t t;
    time_t now;
    
    mytime.tm_year = 120;
    mytime.tm_mon = 3;
    mytime.tm_mday = 29;
    
    mytime.tm_hour = 14;
    mytime.tm_min  = 50;
    mytime.tm_sec  = 0;

    printf("wday : %d\n",mytime.tm_wday);

    t = mktime(&mytime);
    
    now = time(NULL);
    
    printf("%ld : %ld\n",t,now);
    
    printf("wday : %d\n",mytime.tm_wday);
    
    return 0;
}
