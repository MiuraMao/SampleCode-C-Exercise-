#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);    //乱数を生成して返すのみなので引数不要
void wait_enter(void);

int roll_dice(void){
    return rand() % 6 + 1;      //1から6までをランダムに生成して返す
}

/*エンターキーが押されるまで待つ関数*/
void wait_enter(void){
    char dummy;

    printf("サイコロを振るにはエンターキーを押して下さい");
    scanf("%c", &dummy);        //dummyの値は'\n'だろうが、使わない。
    //戻り値を返さないためreturn文は省略
}

int main(void){
    int c_hand1, c_hand2, c_points;
    int u_hand1, u_hand2, u_points;

    srand(time(0));
    c_hand1 = roll_dice();
    c_hand2 = roll_dice();
    c_points = c_hand1 + c_hand2;
    printf("コンピュータ %d + %d = %d点\n", c_hand1, c_hand2, c_points);

    wait_enter();
    u_hand1 = roll_dice();
    printf("１つめは%d\n", u_hand1);
    wait_enter();
    u_hand2 = roll_dice();
    printf("２つめは%d\n", u_hand2);
    u_points = u_hand1 + u_hand2;
    printf("合計%d点\n", u_points);

    if (u_points > c_points)
        printf("あなたの勝ち！！\n");
    else if (u_points < c_points)
        printf("あなたの負け...\n");
    else
        printf("引き分け！\n");
    return 0;        
}