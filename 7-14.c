#include <stdio.h>
//星組の指定したメンバを月組へ移動させる

void show_group(char *, char *[]);

/*name:　に続けて、vの内容を添え字付きで表示する*/
void show_group(char *name, char *v[]){
    printf("%s:",name);
    for (int i = 0; v[i] != NULL; i++)      //空ポインタが見つかるまでループ
        printf(" %d:%s", i, v[i]);          //その文字列を表示
    putchar('\n');                          //１文字標準出力
}

int main(void){
    char *hoshi[10] = {"hiroto", "yuuma", "souta", "minato", "ren", NULL};
    char *tsuki[10] = {"aoi", "haruna", "yui", NULL};
    int i, to, from;

    show_group("Hoshi", hoshi);
    show_group("Tsuki", tsuki);

    printf("移動元の要素の添え字？");
    scanf("%d", &from);
    printf("移動後の位置？");
    scanf("%d", &to);

    /*移動先を空ける*/
    for (i = 0; tsuki[i] != NULL; i++);     //空ポインタを探す（本分は空文「;」）
    /*後ろから順に、後ろに１つずつずらす*/
    for (; i >= to; i--)
        tsuki[i+1] = tsuki[i];
    tsuki[to] = hoshi[from];                //ポインタをコピー
    /*移動元を削除*/
    for (i = from; hoshi[i] != NULL; i++)   //fromより後ろを前に１つずつずらす
        hoshi[i] = hoshi[i+1];              //ループを抜ける直前で空ポインタがコピーされる

        show_group("Hoshi", hoshi);
        show_group("Tsuki", tsuki);
        return 0; 
}