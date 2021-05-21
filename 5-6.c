#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//乱数表

enum { TSIZE = 9 };             //乱数表の行と列の数

int main(void){
    int rnt[TSIZE][TSIZE];      //TSIZE×TSIZEの乱数表
    int i, j;

    printf(" |   2|   3|   4|   5|   6|   7|   8|   9|\n");
    printf("-+----+----+----+----+----+----+----+----+\n");
    /*乱数表を作りながら表示*/
    srand(time(0));
    for (i = 0; i < TSIZE; i++){
        printf("%1d|", i+1);    //添え字がiなら、表の(i+1)行目
        for (j = 0; j < TSIZE; j++){
            rnt[i][j] = rand() % 10000;     //0～9999の範囲の乱数を生成
            printf("%04d|", rnt[i][j]);     //ゼロ詰めして４桁で表示
        }
        printf("\n");
    }

    printf("行？ ");
    scanf("%d", &i);
    printf("列？ ");
    scanf("%d", &j);
    printf("%04dです\n", rnt[i-1][j-1]);    //入力は1～9、添え字は0～8
    return 0;
}