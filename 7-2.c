#include <stdio.h>
/*ライブラリ関数（isupper）を使う方が良い*/

int main(void){
    int c, n;

    n = 0;
    while ((c = getchar()) != EOF){     //ファイルの終わりまで（int型で返す）
        if (65 <= c && c <= 90)         //文字コードがA以上Z以下なら（実行環境に依存）
            n++;                        //大文字として数える
    }
    printf("大文字は%d個ありました\n", n);
    return 0;
}