#include <stdio.h>

int main(void){
    int price, points, tax, pay;

    printf("商品代金（税抜き）？");
    scanf("%d", &price);
    tax = price * 0.08;     //int*doubleはdouble、int型変数に代入して小数部切り捨て（消費税率８％）
    pay = price + tax;      //intで計算、型変換は起きない
    printf("消費税%d円、お支払い額%d円です\n", tax, pay);
    points = pay * 0.1;     //int*doubleがdouble、int型変数に代入して小数部切り捨て
    printf("%dポイントつきました！\n", points);
    return 0;
}