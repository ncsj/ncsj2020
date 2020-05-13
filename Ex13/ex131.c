#include <stdio.h>
#include <time.h>

int  main(){
    time_t  now;
    struct tm *cur;
    int  y;
    int  m;
    int  d;
    
    now = time(NULL);       /* 現在の時刻（日付も含む） */
    now = (time_t)61;       /* nowを61秒に書き直す */

    cur = localtime(&now);
    
    
    /* 日付  --- 2020/4/30*/
    y = cur->tm_year + 1900;
    m = cur->tm_mon + 1;
    d = cur->tm_mday;
    printf("%d/%d/%d\n", y, m, d);
    
    /* 時刻 --- 13:55:01 */
    printf("%02d:%02d:%02d\n",cur->tm_hour,cur->tm_min,cur->tm_sec);
    
    return 0;
}
