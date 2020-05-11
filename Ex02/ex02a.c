#include <stdio.h>

int main(){
    int  array[10];
    int  i;
    int  *p;        /*  ポインター変数の定義  */
    
    p = array;

    for(i=0;i<10;i++){
        *(p+i) = i + 1;
        // p++;    /* p = p + 1; */
    }
    
    for(i=0;i<10;i++){
        printf("array[%d] : %d\n",i,array[i]);
    }
    
    return 0;
}
