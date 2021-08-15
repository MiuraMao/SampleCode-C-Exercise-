#include <stdio.h>
//ニュートン法

#define EPSILON 0.00001

int main(void){
    double a, x;

    printf("ルートいくつ？ ");
    scanf("%lf", &a);
    x = a;
    while (x*x-a < -EPSILON || EPSILON < x*x-a)     //|x*x-a| > EPSILONである間
        x = (x + a / x) / 2;
    printf("%.10fの２乗は%.10f\n", x, x*x);
    return 0;
}