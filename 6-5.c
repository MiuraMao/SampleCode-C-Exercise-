#include <stdio.h>

void reverse(int [], int);

void reverse(int a[], int n){
    int i, t;

    for (i = 0; i < n / 2; i++){        //a[0] <-> a[n-1], a[1] <-> a[n-2], ...
        t = a[i];                       //要素の入れ替え：a[i] <-> a[n-i-1]
        a[i] = a[n-i-1];
        a[n-i-1] = t;
    }
}

int main(void){
    int a[] = {12, 3, 456, 7, 89, 100};
    int i;

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)    //内容を表示
        printf("%d ", a[i]);
    printf("\n");

    reverse(a, sizeof(a)/sizeof(a[0]));             //内容を逆順にする

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)    //内容を表示
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}