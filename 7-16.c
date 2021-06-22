#include <stdio.h>
#include <stdlib.h>
//コマンド行引数（メッセージを繰り返し表示）
//なおargv[3]は空ポインタ

int main(int argc, char *argv[]){   //argcが引数の数、argvが全ての引数へのポインタ配列
    int n;

    if (argc != 3){
        printf("使い方： %s 回数 メッセージ\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);              //argv[1]が回数（文字列）、atoiで整数に
    while (n--)
        printf("%s\n", argv[2]);    //argv[2]がメッセージ
    return 0;
}