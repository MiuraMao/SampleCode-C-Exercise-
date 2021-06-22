#include <stdio.h>
//静的変数（生存期間はプログラム実行の全体）

int deposit(int amount){
    static int balance = 0;         //貯金額を保持する静的変数；初期化は実行開始時のみ

    balance += amount;              //mainへ戻ってもbalanceの領域は有効。ただしブロック有効範囲
    return balance;
}

int main(void){
    int money;

    for (;;){
        printf("入れる金額？ ");
        scanf("%d", &money);
        if (money == 0)
            break;
        printf("貯金額 %d円\n", deposit(money));
    }
    printf("空けます\n");
    return 0;
}