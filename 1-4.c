#include <stdio.h>

int main(void){
    double height, weight, bmi;

    /*入力*/
    printf("身長[cm]？");
    scanf("%lf", &height);
    printf("体重[kg]？");
    scanf("%lf", &weight);

    /*計算*/
    height = height / 100;              //メートルの単位にする
    bmi = weight / (height * height);   //BMIの式

    /*出力*/
    printf("BMIは%.1f, ", bmi);
    if (bmi >= 25)
        printf("肥満です\n");
    else
        printf("肥満ではありません\n");
    return 0;

}