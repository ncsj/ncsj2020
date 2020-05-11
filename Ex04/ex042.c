#include <stdio.h>
#include <time.h>

int main(){
    time_t  now;
    struct tm *tmp;
    const char *months[] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    const char *wdays[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    
    now = time(NULL);
    
    printf("now : %ld\n",now);
    
    printf("----------\n");
    
    tmp = localtime(&now);
    
    printf("YEAR : %d\n",tmp->tm_year + 1900);
    printf("%s %d\n",months[tmp->tm_mon]
                    ,tmp->tm_mday);
    printf("(%s)\n",wdays[tmp->tm_wday]);
    
    printf("%02d:%02d:%02d\n",tmp->tm_hour
                             ,tmp->tm_min
                             ,tmp->tm_sec);
    
    return 0;
}
