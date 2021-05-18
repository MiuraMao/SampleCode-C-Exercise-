#include <stdio.h>
//エラトステネスのふるい

enum { N = 100 };        //Nまでの素数を求める

int main(void){
    int a[N+1] = {0};   //iが素数ならa[i] = 0; a[N]まで使いたいので宣言はa[N+1]
    int i, j;

    /*倍数をふるい落とす*/
    for (i = 2; i <= N; i++){
        if (a[i] == 0){         //iが素数なら、まだ倍数をふるい落としていない
            for (j = i * 2; j <= N; j += i)     //iの倍数は
                a[j] = 1;                       //すべて合成数なのでふるい落とす
        }
    }
    /*残ったものが素数*/
    for (i = 2; i <= N; i++){
        if (a[i] == 0)
            printf("%d ", i);
    }
    printf("\n", i);
    return 0;
}