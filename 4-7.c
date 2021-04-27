#include <stdio.h>

//ブロックにすれば新しい変数を宣言できる
#define SWAP(x, y, type) { type t = x; x = y; y = t; }      //tは一次変数

int main(void){
    int i, j;
    double d, e;

    printf("整数を空白で区切って２つ入力してください");
    scanf("%d %d", &i, &j);
    printf("i=%d, j=%d\n", i, j);
    printf("入れ替えます\n");
    SWAP(i, j, int)                     //ブロックに展開されるのでセミコロンをつけない！
    printf("i=%d j=%d\n", i, j);
    printf("実数を空白で区切って２つ入力して下さい");
    scanf("%lf %lf", &d, &e);
    printf("d=%f, e=%f\n", d, e);
    printf("入れ替えます\n");
    SWAP(d, e, double);
    printf("d=%f, e=%f\n", d, e);
    return 0;
}