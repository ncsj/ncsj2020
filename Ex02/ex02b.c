#include <stdio.h>

int main(){
    int  array[10];
    int  buff[10];
    int  i;
    int  *p;        /*  ポインター変数の定義  */
    int  *q;
    
    p = array;

    for(i=0;i<10;i++){
        *(p+i) = i + 1;
    }
    
    p = array;
    q = buff;
    
    for(i=0;i<10;i++){
        printf("array[%d] : %d\n",i,array[i]);
        // buff[i] = array[i];
        *(q+i) = *(p+i);
    }
    
    
    for(i=0;i<10;i++){
        printf("buff[%d] : %d\n",i,buff[i]);
    }
    return 0;
}
