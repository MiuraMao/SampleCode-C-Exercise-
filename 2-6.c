#include <stdio.h>
/*真偽値*/

int main(void){
    int a, b;

    a = 3;
    b = 2;
    printf("a は %d, b は %d\n", a, b);
    printf("a > b は %d\n", a > b);
    printf("a == b は %d\n", a == b);
    printf("0 < a < 3 は %d\n", 0 < a < 3);     //(0 < a) < 3と解釈され、(0 < a)が真で1のため、1 < 3で真(1) 
    printf("0 < a && a < 3 は %d\n", 0 < a && a < 3);
    printf("a < 4 || 6 < a は %d\n", a < 4 || 6 < a);
    printf("!a は %d\n", !a);   //真偽を反転した結果を返す。ゼロでない値は真のため、a(3)は真、反転すると偽(0)
    return 0;
}