#include <stdio.h>

/*他のファイルにある関数の関数プロトタイプ*/
int push(int);
int pop(void);

int main(void){
    int n;

    printf("0を入力すると１つ抜き、-1を入力すると全部取り出します\n");
    for (;;){
        printf("いくらの領収書？");
        scanf("%d", &n);
        if (n < 0)          //入力が-1なら
            break;          //ループを抜ける
        else if (n == 0){   //入力が0なら
            if ((n = pop()) < 0)        //スタックから取り出し、取り出せないなら
                printf("空です\n");     //メッセージを表示する
            else                        //取り出したなら
                printf("%d円の領収書です\n", n);    //それを表示する
        }else                           //入力が正なら
            push(n);                    //スタックに入れる
    }
    while ((n = pop()) > 0)             //無くなるまでスタックから取り出す
        printf("%d円の領収書\n", n);
    printf("お疲れ様でした！\n");
    return 0;
}