#include <stdio.h>

int main(void){
    int n;

    printf("整数？");
    scanf("%d", &n);
    if (n > 0)
        printf("%dは整数です\n", n);
    else if(n < 0)
        printf("%dは負で、絶対値は%dです\n", n, -n);
    else
        printf("ゼロです\n");
    return 0;
}