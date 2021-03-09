#include <stdio.h>
/*C言語には累乗の演算子はない*/

int main(void){
    double x, density;  //密度
    int population;

    printf("床の一辺の長さ[m]？");
    scanf("%lf", &x);
    printf("人数？");
    scanf("%d", &population);
    density = population / (x * x);     //人口密度を求める式 優先順位が同じの時、左結合
    //もしくは density = population / x / x;
    printf("人口密度は%.3f人/平方メートルです\n", density);
    return 0;
}