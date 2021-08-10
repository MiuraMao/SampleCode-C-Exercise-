#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//線形リスト（一覧）

struct station{
    char name[50];              //駅名
    int express;                //のぞみ停車駅なら１、そうでないなら０
    struct station *next;       //ポインタ
};

int main(void){
    char *station_info[] = {    //線形リストを作るためのデータ
        "1 Tokyo", "1 Shinagawa", "0 Atami", "0 Shizuoka",
        "1 Nagoya", "0 Maibara", "1 Kyoto", NULL
    };
    struct station *head, *tail, *p;    //headは線形リストの先頭要素を指す
    char **sp;                  //文字列へのポインタの配列の要素を１つずつ処理するためのポインタ

    /*線形リストを作る*/
    head = tail = NULL;         //まだ何もつないでいない
    for (sp = station_info; *sp != NULL; sp++){     //駅のデータを１つずつ
        if ((p = malloc(sizeof(struct station))) == NULL){      //構造体領域を確保
            perror("malloc");
            break;
        }
        strcpy(p->name, *sp+2);         //駅名を入れる（char型２つ分進める？）
        p->express = (**sp == '1');     //データ文字列の先頭が'1'ならのぞみ停車駅
        if (tail)                       //すでに１つ以上リストに入れている
            tail->next = p;             //最後の要素の次にpが指す要素をつなぐ
        else                            //まだ１つもリストに入れていない
            head = p;                   //pを先頭の要素とする
        tail = p;                       //いまつないだ要素がいまのところ最後の要素
    }
    tail->next = NULL;                  //最後の要素のnextに空ポインタを入れる

    /*路線を表示*/
    for (p = head; p != NULL; p = p->next)                      //要素１つずつ
        printf("%c %s\n", p->express ? '+' : '|', p->name);     //情報を表示

    /*すべてのノードの領域を解放*/
    while (head){                       //リストにノードがある間
        p = head->next;                 //次の要素へのリンクをとっておいて
        free(head);                     //先頭要素の領域を解放し
        head = p;                       //とっておいたリンクの先を先頭とする
    }
    return 0;
}