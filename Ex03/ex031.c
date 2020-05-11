#include <stdio.h>

int menu(){
    int  n;
    
    printf("1:+  2:-  3:*  4:/  9:EXIT\n");
    printf("SELECT NUMBER > ");
    scanf("%d",&n);
    
    return n;
}

int inputNumber(int n){
    int  num;

    printf("INPUT NUMBER(%d) : ",n);
    scanf("%d",&num);

    return num;
}

int plus(int x,int y){
    int z = 0;
    z = x + y;
    printf("%d + %d = %d\n",x,y,z);
    return z;
}

int minus(int x,int y){
    int z = 0;
    z = x - y;
    printf("%d - %d = %d\n",x,y,z);
    return z;
}

int multiply(int x,int y){
    int z = 0;
    z = x * y;
    printf("%d * %d = %d\n",x,y,z);
    return z;
}

int divide(int x,int y){
    int z = 0;
    z = x / y;
    printf("%d / %d = %d\n",x,y,z);
    return z;
}

int calcurate(int n,int x,int y,int *p){
    int loop = 1;
    switch( n ){
    case 1:
        *p = plus(x,y);
        break;
    case 2:
        *p = minus(x,y);
        break;
    case 3:
        *p = multiply(x,y);
        break;
    case 4:
        *p = divide(x,y);
        break;
    case 9:
        loop = 0;
        break;
    default:
        break;
    }
    return loop;
}

void printResult(int sum,int count){
    int  ave;
    printf("SUM : %d\n",sum);
    
    ave = sum / count;
    printf("AVE : %d\n",ave);
}

int main(){
    int  n;
    int  loop;
    int  x = 0;
    int  y = 0;
    int  z = 0;
    
    int  sum = 0;
    int  count = 0;
    
    loop = 1;
    
    while(loop == 1){
        n = menu();
        
        if((n>=1) && (n<=4)){
            x = inputNumber(1);
            y = inputNumber(2);
        }
        
        z = 0;
        loop = calcurate(n,x,y,&z);
        
        if(loop != 0){
            sum = sum + z;
            count++;
        }
    }

    printResult(sum, count);

    return 0;
}

