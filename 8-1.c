#include <stdio.h>
//外部変数（生存期間はプログラム実行の全体）

double jpy_usd;                 //外部変数の定義宣言

int usd_to_jpy(double);         //関数プロトタイプ

int usd_to_jpy(double d){
    return jpy_usd * d;         //戻り値の型がintなので小数点以下切り捨てになる
}

int main(void){
    double d;
    int y;

    printf("１ドルは何円？ ");
    scanf("%lf", &jpy_usd);     //外部変数に為替レートを読み込む
    printf("何ドル？ ");
    scanf("%lf", &d);
    y = usd_to_jpy(d);          //USDをJPYに両替
    printf("%.2fドルは%d円になります\n", d, y);
    return 0;
}