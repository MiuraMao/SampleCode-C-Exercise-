#include <stdio.h>

enum { N = 3 };                 //N×Nの魔法陣（Nは奇数）

int main(void){
    int a[N][N] = {{0}};        //最初の要素を０で初期化し、残りも無指定なので初期値０
    int i, j, n, sum, nexti, nextj;

    /*魔法陣を作る*/
    i = 0;                      //最初に入れる位置は、最上段
    j = N / 2;                  //の中央
    for (n = 1; n <= N * N; n++){   //1からN*Nまでを入れる
        a[i][j] = n;            //現在の位置にnを入れる
        /*右上の位置をnexti、nextjに求める*/
        if ((nexti = i - 1) < 0)    //上へ；最上段を超えたら
            nexti = N - 1;          //ぐるりと一番下に
        if ((nextj = j + 1) >= N)   //右へ；右端を超えたら
            nextj = 0;              //ぐるりと左端へ
        /*右上に行くか下に行くかの判断*/
        if (a[nexti][nextj] == 0){      //右上は空いている？
            i = nexti;                  //なら次はそこ
            j = nextj;
        } else {                        //右上が空いていない
            if (++i >= N)               //次はすぐ下；最下段を超えたら
                i = 0;                  //ぐるりと一番上へ
        }
    }
    /*できた魔法陣を表示する*/
    for (i = 0; i < N; i++){
        printf("+");
        for (j = 0; j < N; j++)
            printf("---+");
        printf("\n|");
        for (j = 0; j < N; j++)
            printf("%3d|", a[i][j]);
        printf("\n");
    }
    printf("+");
    for (j = 0; j < N; j++)
        printf("---+");
    printf("\n");
    return 0;
}