#include <stdio.h>
#include <stdlib.h>

int  main(){
    int  *p;
    int  i;
    
    p = (int *)malloc( sizeof(int) * 10 );
    
    for(i=0;i<10;i++){
        *(p+i) = i + 200;
    }
    
    for(i=0;i<10;i++){
        printf("[%d] : %d\n",i,*(p+i));
    }
    
    free( p );
    
    return 0;
}
