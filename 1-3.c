#include <stdio.h>

int main(void){
    int n;

    printf("decimal number?");
    scanf("%d", &n);                    //10進数
    printf("hexadecimal = %x\n", n);    //16進数
    return 0;
}