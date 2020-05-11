#include <stdio.h>

int main(){
    int  x;
    
    printf("INPUT x : ");
    scanf("%d",&x);
    
    switch( x ){
    case 1:
            printf("おはようございます。\n");
            break;
    case 2:
            printf("こんにちは\n");
            break;
    case 0:
            printf("お疲れ様です。\n");
            break;
    default:
            printf("さようなら！\n");
            break;
    }
    
    return 0;
}
