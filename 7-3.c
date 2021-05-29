#include <stdio.h>
#include <ctype.h>
/*標準出力（stdout）*/

int main(void){
    int c;

    while ((c = getchar()) != EOF){     //ファイルの終わりまで
        if (isdigit(c))                 //cが数字なら
            putchar('X');               //'X'を出力する
        else                            //そうでなければ
            putchar(c);                 //入力のcをそのまま出力する
    }
    return 0;
}
