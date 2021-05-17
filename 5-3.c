#include <stdio.h>

enum { NMAX = 100 };                     //りんごの最大個数（列挙定数）

int main(void){
    int i, n, grams, apple[NMAX];
    double sum, ave;

    n = 0;
    printf("重さを入力して下さい（0で終了）\n");
    while (n < NMAX){
        printf("重さ？");
        scanf("%d", &grams);
        if (grams == 0)         //０が入力されたら
            break;              //入力終了
        apple[n++] = grams;
    }
    /*ここではnは入力データ数になっている*/

    /*平均を求める*/
    sum = 0;
    for (i = 0; i < n; i++)     //総和を求めて
        sum += apple[i];
    ave = sum / n;              //個数で割ると平均
    printf("平均%.1fグラム\n平均以上の重さのもの", ave);
    for (i = 0; i < n; i++)
        if (apple[i] >= ave)            //平均以上なら
            printf(" %d", apple[i]);    //表示する
    printf("\n");
    return 0;
}