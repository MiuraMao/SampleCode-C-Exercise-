#include <stdio.h>

int main(void){
    //あらかじめ要素の値が決まっている場合は初期化が便利
    int nday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;

    printf("西暦何年？");
    scanf("%d", &year);

    /*うるう年の補正*/
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        nday[1] = 29;
    
    printf("[%d年]\n", year);
    for (int i = 0; i < 12; i++){
        printf("%2d月%d日　", i+1, nday[i]);
        if (i % 4 == 3)     //月４つごとに
            printf("\n");   //改行する
    }
    return 0;
}