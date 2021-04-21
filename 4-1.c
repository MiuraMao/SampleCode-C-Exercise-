#include <stdio.h>

void teaspoon(int);                 //関数プロトタイプ

void teaspoon(int n){               //１さじ, ... , nさじ　を表示する
    for (int i = 1; i <= n; i++){
        printf("%dさじ", i);
        if (i < n)
            printf(", ");
    }
    printf("\n");
    return;
}

int main(void){
    int cups;

    for (;;){
        printf("何杯？");
        scanf("%d", &cups);
        if (cups == 0)              //０なら終了
            break;
        teaspoon(cups + 1);         //cups+1さじの茶葉を入れる
        printf("お湯を注ぐ...\n");
        printf("お茶をどうぞ！\n");        
    }
    printf("またどうぞ\n");
    return 0;
}