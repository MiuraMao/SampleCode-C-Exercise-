#include <stdio.h>
#include <stdlib.h>

double rate;                    //消費税率[%]
int calctax(int);               //別ファイルにある関数を呼ぶための関数プロトタイプ

int main(int argc, char **argv){
    int price, tax;

    rate = atof(argv[1]);       //税率をコマンド行引数から得る（初期化は定義のところで行う）
    printf("商品の価格？ ");
    scanf("%d", &price);
    tax = calctax(price);       //別ファイルにある関数を呼び出す
    printf("消費税%d円、税込金額%d円\n", tax, price+tax);
    return 0;
}