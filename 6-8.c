#include <stdio.h>
#include <stdlib.h>     //malloc,exit,EXIT_FAILUREを使う
//動的メモリ確保

int main(void){         
    int *tnum, n;           //tnumはゼッケン番号の配列領域を指す；nは競技者数
    double *qtime;          //タイムの配列領域を指す

    printf("競技者数？ ");
    scanf("%d", &n);
    if ((tnum = malloc(sizeof(int)*n)) == NULL){        //ゼッケン番号の領域確保
        perror("malloc");       //エラーメッセージの出力
        exit(EXIT_FAILURE);     //プログラム終了
    }
    if ((qtime = malloc(sizeof(double)*n)) == NULL){    //タイムの領域確保
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++){
        printf("ゼッケン番号？ ");
        scanf("%d", &tnum[i]);
        printf("#%dのタイム？ ", tnum[i]);
        scanf("%lf", &qtime[i]);
    }
    printf("--- 結果 ---\n");
    for (int i = 0; i < n; i++)
        printf("#%d: %.3f秒\n", tnum[i], qtime[i]);
    free(tnum);                 //ゼッケン番号の領域解放
    free(qtime);                //タイムの領域解放
    return 0;
}