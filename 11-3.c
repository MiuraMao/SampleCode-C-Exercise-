#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//線形リストの削除
//領域を動的に確保したなら、削除後に解放すると良い

struct station{
    char name[50];          //駅名
    int express;            //のぞみ停車駅なら１
    struct station *next;   //リンク
};

char *station_info[] = {    //路線データ
    "1 Tokyo", "1 Shinagawa", "0 Atami", "0 Shizuoka",
    "1 Nagoya", "0 Maibara", "1 Kyoto", NULL
};

struct station *make_line(void);
void show_line(struct station *);
void free_line(struct station *);

/*make_line - 線形リストを作る*/
struct station *make_line(void){
    struct station *head, *tail, *p;
    char **sp;

    head = tail = NULL;
    for (sp = station_info; *sp != NULL; sp++){
        if ((p = malloc(sizeof(struct station))) == NULL){
            perror("malloc");
            break;
        }
        strcpy(p->name, *sp+2);
        p->express = (**sp == '1');     //文字列で判定
        if (tail)
            tail->next = p;
        else
            head = p;
        tail = p;
    }
    tail->next = NULL;
    return head;                           //先頭要素へのポインタを返す
}

/*show_line - 路線を表示する*/
void show_line(struct station *head){
    struct station *p;

    for (p = head; p != NULL; p = p->next)
        printf("%c %s\n", p->express ? '+' : '|', p->name);
}

/*free_line - 線形リストを解放する*/
void free_line(struct station *head){
    struct station *p;

    while (head){
        p = head->next;
        free(head);
        head = p;
    }
}

//11-3.cで変更部分
int main(void){
    struct station *head, *p, *prev;    
    char name[50];

    head = make_line();         //線形リストを作る
    show_line(head);            //路線を表示

    printf("どの駅を削除しますか？ ");
    scanf("%s", name);
    prev = NULL;
    for(p = head; p != NULL; p = p->next){      //pで指定された駅を探す
        if (strcmp(p->name, name) == 0)         //見つけたら
            break;                              //ループを抜ける
        prev = p;                               //１つ前のノードをprevで指しておく
    }
    if (p == NULL){
        printf("%sという駅はありません\n", name);
        exit(EXIT_FAILURE);
    }
    /*pが指すノードを削除するには、pの次をprev->nextに指させる*/
    if (prev == NULL)                           //pが先頭ノードなら
        head = head->next;                      //pの次のノードを先頭にする
    else                                        //pが先頭ノードでないなら
        prev->next = p->next;                   //pの次をprev->nextに指させる
    printf("%sを解放します！\n", p->name);       //pが先頭ノードの場合はp=head
    free(p);                                    //削除したノードの領域を解放

    show_line(head);                            //路線を表示
    free_line;                                  //全ノードの領域を解放
    return 0;
}
