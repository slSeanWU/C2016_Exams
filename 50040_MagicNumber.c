#include <stdio.h>
#include <stdlib.h>
 
int main(void){
    int a;
    scanf("%d", &a);
 
    int b;
    if(a <= 0) b = 0;
    else if(a%2) b = 0;
    else if(a >= 1000 && a <= 10000) b = 0;
    else b = 1;
 
    printf("%d\n", b);
 
    return 0;
}