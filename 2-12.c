#include <stdio.h>
//浮動小数点の誤差
//==や!=で比較するコードはめったに書かない

int main(void){
    int n, i;
    double n_inv, is_one;

    printf("正の整数を１つ入れて下さい");
    scanf("%d", &n);
    n_inv = 1.0 / n;        //nはintなので1.0と演算してdoubleにする
    is_one = 0;
    for (i = 0; i < n; i++) //1/nをn回足す
        is_one += n_inv;
    printf("%fを%d解足すと%f\n", n_inv, n, is_one);
    if (is_one == 1.0)
        printf("戻りました\n");
    else
        printf("戻りません\n");
    return 0;
}