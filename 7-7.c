#include <stdio.h>
//回文（Palindrome）の判定

int main(void){
    char s[1024], *p, *q;

    printf("文字列？");
    fgets(s, sizeof(s), stdin);
    /*改行文字があれば取り除く*/
    for (p = s; *p != '\0'; p++){
        if (*p == '\n'){
            *p = '\0';      //改行文字を空文字で上書き
            break;
        }
    }
    if (s[0] == '\0'){
        printf("空文字列です\n");
    } else {
        /*文字列末尾の空文字を探す*/
        q = s;
        while (*q != '\0')
            q++;
        /*先頭と末尾から見ていく*/
        q--;                //末尾の文字をqに指させる
        p = s;              //先頭の文字をpに指させる
        while (p < q){      //pとqが出会うまでの間
            if (*p != *q)   //等しくない文字があれば回文でないので
                break;      //ループをbreakする
            p++;            //pを後ろに進め、
            q--;            //qを前に進める
        }
        if (p < q)          //ｚｗループ条件が成り立っているならbreakしてきたはず
            printf("「%s」は回文ではありません\n", s);
        else
            printf("「%s」は回文です", s);
    }
    return 0;
}