#include <stdio.h>
//文字列へのポインタ

int main(void){
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};      //それぞれ文字列への先頭ポインタ
    int i;

    for (i = 0; hoshi[i] != NULL; i++)      //空ポインタが見つかるまで
        printf("%s\n", hoshi[i]);
    return 0;
}