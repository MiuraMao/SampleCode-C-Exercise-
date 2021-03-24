#include <stdio.h>

int main(void){
    int n, i, score;
    double sum;

    printf("科目数？");
    scanf("%d", &n);

    sum = 0;
    for (i = 1; i <= n; i++){
        printf("科目%dの点数？", i);
        scanf("%d", &score);
        sum += score;   //sumにscoreを足し込む
    }
    printf("平均%.1f点\n", sum/n);  //（合計点／科目数）が平均点
    return 0;
}