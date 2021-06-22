#include <stdio.h>
//引数を連結して表示する

void concat(char *, char *);

void concat(char *p, char *q){
    if (*p){                    //pが空文字列でないなら
        while (*p)              //pの末尾を
            p++;                //探して
        *p++ = '_';             //下線を追加する(次の位置を指す)
    }
    while (*q)                  //qの文字を１つずつ
        *p++ = *q++;            //pに追加する
    *p = '\0';                  //空文字で終端する
}

int main(int argc, char *argv[]){
    char s[1024] = "";          //領域は十分に大きいとする

    while (*++argv)             //argv[1]から順に（空ポインタで抜ける）
        concat(s, *argv);       //１つずつsに追加していく(p, q)
    printf("%s\n", s);
    return 0;
}