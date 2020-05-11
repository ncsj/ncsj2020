#include <stdio.h>

int main(){
    int  n;
    int  a;
    
    printf("INPUT NUMBER\n");
    printf(">");
    scanf("%d",&n);
    
    a = n % 2;
    if(a == 1){
        printf("%d : odd\n",n);
    }
    else{
        printf("%d : even\n",n);
    }
    
    return 0;
}
