#include <stdio.h>

int main(void){
    int i;

    //%zuが使えないため%luで代用
    printf("sizeof(int) = %lu\n", sizeof(int));     
    printf("sizeof(i) = %lu\n", sizeof(i));
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(short int) = %lu\n", sizeof(short int));
    printf("sizeof(long int) = %lu\n", sizeof(long int));
    printf("sizeof(float) = %lu\n", sizeof(float));
    printf("sizeof(double) = %lu\n", sizeof(double));
    return 0;
}