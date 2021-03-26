#include <stdio.h>

int main(void){
    double x, y, answer;
    int oper;

    printf("x?");
    scanf("%lf", &x);
    printf("y?");
    scanf("%lf", &y);
    printf("演算を選んで下さい 1:加算, 2:減算, 3:乗算, 4:除算 ？ ");
    scanf("%d", &oper);
    switch (oper){
        case 1:         //ラベル定数は整数に限られる
            answer = x + y;
            break;
        case 2:
            answer = x - y;
            break;
        case 3:
            answer = x * y;
            break;
        case 4:
            answer = x / y;
            break;
        default:        //エラーの場合
            printf("演算の指定が間違っています\n");
            return 0;   //プログラム終了
    }
    printf("答え %lf\n", answer);
    return 0;
}