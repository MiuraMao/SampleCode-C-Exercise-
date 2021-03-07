#include <stdio.h>

int main(void){
    double r, v;

    printf("球の半径[cm]？");
    scanf("%lf", &r);
    v = 4 * 3.14 * r * r * r / 3;           //4 / 3 * 3.14...とすると4/3がintの除算となり1になってしまう
    printf("半径%.1fcmの球の体積は約%.2fccです。\n", r, v);
}