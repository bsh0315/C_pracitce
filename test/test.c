#include <stdio.h>

int add(int x[], int size){
    printf("%d", sizeof(x));

    return 1;
}

int main(){
    int a[10] = {1,2,3,4,5,0};
    add(a, sizeof(a)/sizeof(int));
    
    return 0;
}