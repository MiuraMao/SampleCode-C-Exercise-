#include <stdio.h>
//標準入力（stdin）

int main(void){
    int c;

    printf("文字列を入力して下さい：");
    while((c = getchar()) != '\n')        //改行文字に出会うまで（int型で返す）
        printf("文字'%c' 文字コード%d\n", c, c);    //%cで文字を、%dでコードを表示
    return 0;
}