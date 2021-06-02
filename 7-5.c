#include <stdio.h>
#include <ctype.h>
//1文字を扱う型：EOFとともに扱う時はint型、1バイト整数値として扱う時はunsigned char型

int kind(unsigned char);    //1バイト文字のみ渡され、EOFは渡されないため、unsigned char型

int kind(unsigned char c){
    if (islower(c))         //小文字
        return 0;
    else if (isupper(c))    //大文字
        return 1;
    else if (isdigit(c))    //数字
        return 2;
    else if (isspace(c))    //空白類文字
        return 3;
    else                    //その他
        return 4;
}

int main(void){
    int c;                  //EOFを扱うためint型

    while ((c = getchar()) != EOF){
        switch(kind(c)){    //型変換が起こる
            case 0: putchar('x'); break;
            case 1: putchar('X'); break;
            case 2: putchar('0'); break;
            case 3: putchar('_'); break;
            case 4: putchar('.'); break;
        }
        if (c == '\n')      //cが改行文字なら、上で出力した'_'に加えて
            putchar('\n');  //さらに改行文字を出力する
    }
    return 0;
}