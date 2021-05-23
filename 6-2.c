#include <stdio.h>

void cancel(int *, int *);

void cancel(int *np, int *dp){      //仮引数でポインタを受け取る（参照型）
    int fact = 2;

    while (fact <= *dp){            //２から分母（*dp）までの
        if (*np % fact == 0 && *dp % fact == 0){    //両者を割り切れる数で
            *np /= fact;    //約分
            *dp /= fact;    //していく
        }else   fact++;
    }
}

int main(void){
    int n, d;

    printf("分子？");
    scanf("%d", &n);
    printf("分母？");
    scanf("%d", &d);
    cancel(&n, &d);     //ポインタを渡して、その領域を使って計算させる
    printf("約分すると %d/%d\n", n, d);
    return 0;
}