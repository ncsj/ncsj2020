#include <stdio.h>

void printArray(int *p){
    int  i;
    
    for(i=0;i<10;i++){
        printf("array[%d] : %d\n",i,*(p+i));
    }
}

int main(){
    int  array[10];
    int  i;
    
    for(i=0;i<10;i++){
        array[i] = i + 1;
    }
    
    printArray(array);
}
