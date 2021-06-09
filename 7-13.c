#include <stdio.h>
//要素を挿入する

void show_group(char *, char *[]);

/*name:　に続けて、vの内容を添え字付きで表示する*/
void show_group(char *name, char *v[]){         //配列はポインタとして評価される（Char **v）
    printf("%s:", name);
    for (int i = 0; v[i] != NULL; i++)          //空ポインタが見つかるまでループ
        printf(" %d:%s", i, v[i]);              //その文字列を表示
    putchar('\n');
}

int main(void){
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};
    char *tsuki[10] = {"aoi", "haruna", "yui", NULL};
    int i, to, from;

    show_group("Hoshi", hoshi);
    show_group("Tsuki", tsuki);

    printf("星組のどの人？（添え字を入力）");
    scanf("%d", &from);
    printf("月組に入れる位置？");
    scanf("%d", &to);

    /*コピー先を空ける*/
    for (i = 0; tsuki[i] != NULL; i++);         //空ポインタを指す（本体は空文「;」）
    /*後ろから順に、後ろに１つずつずらす*/
    for (; i >= to; i--)
        tsuki[i+1] = tsuki[i];
        tsuki[to] = hoshi[from];                //ポインタをコピー

        show_group("Hoshi", hoshi);
        show_group("Tsuki", tsuki);
        return 0;

}