#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int u_hand, c_hand;

    srand(time(0));             //乱数の種を与えるのは最初に一度だけ
    for (;;){
        printf("あなたの手 ぐう=0 ちょき=1 ぱあ=2 ？");
        scanf("%d", &u_hand);

        c_hand = rand() % 3;    //0から2までの整数の乱数を生成
        printf("コンピュータ ");
        switch (c_hand){
            case 0: printf("ぐう"); break;
            case 1: printf("ちょき"); break;
            case 2: printf("ぱあ"); break;
        }
        printf(", あなた ");
        switch (u_hand){
            case 0: printf("ぐう"); break;
            case 1: printf("ちょき"); break;
            case 2: printf("ぱあ"); break;
        }
        printf("\n");
        if (c_hand != u_hand)   //勝負がついた
            break;
        printf("あいこでしょ\n");
    }
    if ((u_hand + 1) % 3 == c_hand)     //3を法とする合同を利用
        printf("あなたの勝ちです！\n");
    else
        printf("あなたの負けです・・・\n");
    return 0;
}