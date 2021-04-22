#include <stdio.h>

double round_to(double, int);       //関数プロトタイプ

/*xを四捨五入して小数点以下n桁までにする*/
double round_to(double x, int n){
    double mul = 1, result;
    
    for (int i = 0; i < n; i++)     //10のn乗を求める
        mul *= 10;
    result = (int)(x * mul + 0.5) / mul;    //四捨五入
    return result;                  //resultの値を戻り値として戻る
}

int main(void){
    double val, rounded;
    int n;

    printf("数値？ ");
    scanf("%lf", &val);
    printf("小数点以下の桁数？ ");
    scanf("%d", &n);
    rounded = round_to(val, n);     //valを小数点以下n桁までにする
    printf("%f\n", rounded);
    return 0;                       //main関数のreturn 0は省略可（本体最後の}で戻り値０で戻る）
}