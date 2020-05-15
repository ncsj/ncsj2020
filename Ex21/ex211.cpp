#include <stdio.h>

class DATA{
private:
    int  x;
    int  y;

public:
    void print(){
        printf("%d,%d\n",x,y);
    }

    void set(int a,int b){
            x = a;
            y = b;
    }
};

int main(){
    struct DATA  data;

    data.set(100,200);
    data.print();

    return 0;
}
