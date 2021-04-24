#include <stdio.h>
//なお標準ライブラリに累乗を求める関数double powがある（ヘッダmath.h）

double power(double, int);
int compound(int, int, double);

/*xのn乗を求める*/
double power(double x, int n){
    double y = 1.0;

    while(n-- > 0)
        y *= x;
    return y;
}
int compound(int p, int y, double r){
    return p * power(1 + r, y);         //複利計算の式
}

int main(void){
    int pv, final, years;
    double rate;

    printf("最初の金額[円]？");
    scanf("%d", &pv);
    printf("複利の年利率[%%]？");
    scanf("%lf", &rate);
    printf("年数？");
    scanf("%d", &years);
    final = compound(pv, years, rate / 100);    //rateは％なので100で割る
    printf("%d年後の金額は%d円です\n", years, final);
    return 0;
}