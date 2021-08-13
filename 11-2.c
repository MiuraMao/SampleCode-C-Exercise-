#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//線形リストの探索

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
struct station *find_station(char *, struct station *);

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
    return head;                           //先頭要素へのポインタを返す（80行目で使用するため）
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

/*find_station - 指定された名前の駅を探す（なければNULLを返す）*/
struct station *find_station(char *name, struct station *head){
    struct station *p;

    for (p = head; p != NULL; p = p->next){     //ノードを１つずつ見る
        if (strcmp(p->name, name) == 0)         //駅名が一致したら
            break;                              //ループを抜ける
    }
    return p;   //ループを回り切ったらpはNULL、breakしたなら見つけたノード
}

int main(void){
    struct station *head, *p;
    char name[50];

    head = make_line();         //路線を読んで線形リストを作る
    show_line(head);            //路線表示
    printf("駅名？ ");
    scanf("%s", name);
    if ((p = find_station(name, head)) == NULL)     //駅を探す
        printf("%sという駅はありません\n", name);
    else if (p->express)
        printf("のぞみ停車駅です\n");
    else
        printf("のぞみは停まりません\n");
    free_line(head);            //線形リストを解放
    return 0;
}
