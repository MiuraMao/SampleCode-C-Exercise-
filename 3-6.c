#include <stdio.h>

int main(void){
    int i, j, sum;

    i = 1;
    while (i <= 10000){
        sum = 0;
        /*iの約数を探して和を求める*/
        j = 1;
        while (j < i){  //iより小さい数について
            if (i % j == 0)     //それが約数なら
                sum += j;       //sumに足し込む
            j++;
        }
        /*約数の和が自身に一致したら完全数なので表示*/
        if (sum == i)
            printf("%d\n", i);
        i++;
    }
    return 0;
}