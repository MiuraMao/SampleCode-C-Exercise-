#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "8-5_myheader.h"       //共通の宣言を取り込む

/*1行読み込む共通処理*/
static void get_line(char *p, int size){        //main.cから呼び出さないためstaticを付けてファイル有効範囲とした
    do {
        fgets(p, size, stdin);
    }while (*p == '\n');        //改行だけの行は捨てる（scanfが読み取った後、入力を残す改行文字を捨てるため）
    while (*p){
        if (*p == '\n'){        //改行文字があれば
            *p = '\0';          //空文字で上書きして取り除く
            break;
        }
        p++;
    }
}

/*本の情報を外部変数に読み込む*/
void read_books(void){
    char *p;

    nbooks = 0;
    for (;;){
        if ((p = malloc(TITLESIZE)) == NULL){   //題名の領域を確保
            perror("malloc");
            break;
        }
        printf("#%d 題名：", nbooks);
        get_line(p, TITLESIZE);             //題名をキーボードから読み込む
        if (p[0] == '.' && p[1] == '\0'){   //入力が.だけなら
            free(p);                        //確保した領域を解放して
            return;                         //読み込みを終了
        }
        books[nbooks] = p;                  //題名を入れた文字列を配列に追加
        printf("#%d 値段：", nbooks);
        scanf("%d", &prices[nbooks]);        //値段を読み込む
        nbooks++;                           //1冊読み込んだのでインクリメント
    }
}

void search_books(void){
    char buf[TITLESIZE];
    int i;

    for (;;){
        printf("探す本？");
        get_line(buf, TITLESIZE);               //探す本の題名をキーボードから読む
        if (buf[0] == '.' && buf[1] == '\0')    //入力が.なら
            return;                             //戻る
        for (i = 0; i < nbooks; i++){           //保持しているデータから（nbookの最後は「.」）
            if (strcmp(buf, books[i]) == 0)     //その題名の本を探す
                break;                          //見つかったらbreak
        }
        if (i < nbooks)                         //ループ条件が成り立っているならbreakしてきた
            printf("見つかりました。「%s」%d円です\n", books[i], prices[i]);
        else                                    //ループを回りきった
            printf("見つかりません...\n");
    }
}