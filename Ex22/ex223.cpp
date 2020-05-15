//
//  ex223.cpp
//  Ex22
//
//  Created by 瀬川健児 on 2020/05/13.
//  Copyright © 2020 瀬川健児. All rights reserved.
//

#include <stdio.h>

int plus(int x,int y){
    return x + y;
}

int plus(int x,int y,int z){
    return x + y + z;
}

int plus(int *array, int size){
    int sum = 0;
    
    for(int i=0;i<size;i++){
        sum = sum + *(array+i);
    }
    
    return sum;
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    
    // 関数のオーバーロード
    int  n1 = plus(10,20);
    int  n2 = plus(10,20,30);
    int  n3 = plus(array,10);
    
    printf("%d , %d , %d\n",n1,n2,n3);
    return 0;
}
