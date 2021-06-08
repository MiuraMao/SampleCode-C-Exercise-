#include <stdio.h>
#include <stdlib.h>
//動的メモリ確保

char *mgets(void);

char *mgets(void){
    char *p, *newp;
    int c;
    size_t sz = 1;                  //現在の領域のサイズを覚えておく変数

    if ((p = malloc(sz)) == NULL)    //まず１文字分の領域を確保
        return NULL;
    while ((c = getchar()) != EOF){
        if (c == '\n')              //改行文字がきたらループ終了
            break;
        if ((newp = realloc(p, sz+1)) == NULL)      //領域を１バイト増やそう（拡張後の領域のアドレスが同じと限らない）
            break;                  //増やせなかった・・・まあここまでを結果としよう
        p = newp;                   //増やせたので、新しい領域へのポインタをpへ
        sz++;                       //領域のサイズに１を足す
        p[sz-2] = c;                //一番後ろの１つ前に文字を入れる（一番後ろは常に空き）
    }
    p[sz-1] = '\0';                 //必ず空いている一番後ろに空文字を入れて終端
    return p;
}

int main(void){
    char *vnam, *fnam;

    printf("ファーストネーム？ ");
    vnam = mgets();
    printf("ファミリーネーム？ ");
    fnam = mgets();
    printf("ようこそ, %s %sさん！\n", vnam, fnam);
    free(fnam);                     //mgetsで確保した領域を解放
    free(vnam);                     //（同上）
    return 0;
}