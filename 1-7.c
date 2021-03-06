#include <stdio.h>
#include <stdlib.h>
/*状態はプログラム開始時にリセットされるため、実行するたびに同じ数の列を表示*/
/*内部状態を外から変えるには、srandを使用する*/

int main(void){
    int i, n;

    for (i = 0; i < 5; i++){
        n = rand();             //整数の乱数を得て
        printf ("%d\n", n);     //表示する
    }
    printf("%d = RAND_MAX\n", RAND_MAX);     //乱数値はこの値を超えないはず（RAND_MAXはstdlib.hで定義）
    return 0;
}