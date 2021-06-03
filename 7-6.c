#include <stdio.h>

int main(void){
    char str[] = "Hello!";
    int i;

    i = 0;
    /*文字列の末尾を探す*/
    while (str[i] != '\0')      //空文字を探す
        i++;
    i--;                        //その直前が末尾の文字
    /*先頭まで逆順に表示する*/
    while (i >= 0){
        putchar(str[i]);
        i--;
    }
    putchar('\n');
    return 0;    
}