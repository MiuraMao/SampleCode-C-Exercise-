#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//線形リストの追加

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

//11-4.cで変更部分
int main(void){
    struct station *head, *p, *prev;
    char name[50], yn[10];

    head = make_line();
    show_line(head);

    printf("どの駅の前に追加しますか？ ");
    scanf("%s", name);
    prev = NULL;
    for (p = head; p != NULL; p = p->next){     //指摘された駅を探す
        if (strcmp(p->name, name) == 0)
            break;
        prev = p;                               //直前のノードへのポインタを保持
    }
    if (p == NULL){
        printf("%sという駅はありません\n", name);
        exit(EXIT_FAILURE);
    }

    /*新駅のノード領域を確保*/
    if ((p = malloc(sizeof(struct station))) == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    /*駅のデータを入力*/
    printf("駅名？ ");
    scanf("%s", p->name);
    printf("のぞみ停車駅[y/n]？ ");
    scanf("%s", yn);
    p->express = (*yn == 'y' || *yn == 'Y');    //yかYなら１、そうでないなら０

    /*リストに入れる*/
    if (prev == NULL){                          //見つけた駅が先頭のノードなら
        p->next = head;                         //そのノードに自分の次をつなぐ
        head = p;                               //自分を先頭のノードとする
    }else{                                      //見つけたのが先頭ではないなら
        p->next = prev->next;                   //そのノードを自分の次につなぐ
        prev->next = p;                         //自分をprevの次につなぐ
    }

    show_line(head);
    free_line(head);
    return 0;
}