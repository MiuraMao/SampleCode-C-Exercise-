#include <stdio.h>
//オペランドの評価順序（&& || ?:）

int main(void){
    int npeople, ncakes;

    printf("お菓子の個数？");
    scanf("%d", &ncakes);
    printf("人数？");
    scanf("%d", &npeople);
    if (npeople != 0 && ncakes % npeople  == 0) //0除算で実行時エラーとならないようにする
        printf("配り切れます\n");
    else
        printf("余ります\n");
    return 0;
}