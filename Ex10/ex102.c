#include <stdio.h>

#define   TRUE      1
#define   FALSE     0

int  isPrime(int n){
    int  rtc = TRUE;
    int  x;
    int  i;
    for(i=2;i<=n/2;i++){
        x = n % i;
        if(x == 0){
            rtc = FALSE;
            break;
        }
    }
    
    return rtc;
}

int main(){
    int  n;
    int  r;
    
    printf("INPUT NUMBER > ");
    scanf("%d",&n);
    
    r = isPrime( n );
    if(r == TRUE){
        printf("%d : prime number\n",n);
    }
    else{
        printf("%d : not prime number\n",n);
    }
    
    return 0;
}
