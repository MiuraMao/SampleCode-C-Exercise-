#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int u_hand, c_hand;
    int money = 200;

    srand(time(0));
    while (100 <= money && money < 500){        //掛け金が出せて、手持ちが500円未満
        money -= 100;
        printf("掛け金を払いました。所持金%d円\n", money);
        for (;;){
            printf("あなたの手 ぐう=0 ちょき=1 ぱあ=2 ？");
            scanf("%d", &u_hand);

            /*コンピュータの手を決める*/
            c_hand = rand() % 3;                //0から2までの整数の乱数を生成

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
            if (u_hand != c_hand)               //勝負がついた
                break;
            printf("あいこでしょ\n");
        }
        if ((u_hand + 1) % 3 == c_hand){        //3を法とする合同を利用
            printf("あなたの勝ちです！\n");
            money += 200;
        }else
            printf("あなたの負けです・・・\n");
        printf("所持金は%d円です\n", money);
    }
    printf("ゲーム終了です。");
    if (money < 100)
        printf("残念でした。\n");
    else
        printf("おめでとう！\n");
    return 0;
}