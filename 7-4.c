#include <stdio.h>
#include <ctype.h>
//行頭の文字を大文字にする

int main(void){
    int c, pc;              //pc: １つ前の文字（previous character）

    pc = '\n';              //最初の文字を行頭扱いにするため
    while ((c = getchar()) != EOF){
            if (pc == '\n')     //いま行頭なら
                putchar(toupper(c));    //小文字なら大文字に、それ以外はそのまま
            else                //そうでなければ
                putchar(c);     //cをそのまま出力
            pc = c;             //いま出力した文字を覚えておく
    }
    return 0;
}