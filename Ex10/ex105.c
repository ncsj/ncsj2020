#include <stdio.h>

int order(const int *p,int val){
    int  count = 0;
    int  i;
    
    for(i=0;i<10;i++){
        if(*(p+i) < val){
            count++;
        }
    }
    return count;
}

void sort(int *dest,int *src){
    int  i;
    int  n;
    
    for(i=0;i<10;i++){
        n = order(src,*(src+i));
        *(dest+n) = *(src+i);
    }
}

int main(){
    /* 中の数値は10個に限定しましょう。 */
    int array[] = {100,20,300,40,55,66,700,80,90,10};
    int array2[10]; /* ソートした結果をこの配列へ格納します。 */
    int  i;
    int  n;
    
    for(i=0;i<10;i++){
        printf("[%d] %d\n", i, array[i]);
    }
    
    n = order(array,array[0]);
    printf("%d : %d\n",array[0],n+1);
    
    sort(array2,array); /* arrayの内容をソートした結果を、array2へ格納する */
    
    for(i=0;i<10;i++){
        printf("[%d] %d\n",i,array2[i]);
    }
    
    return 0;
}
