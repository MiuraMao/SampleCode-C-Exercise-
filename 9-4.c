#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//構造体を要素とする配列

struct preca{
    char name[100];                 //プリカ名
    struct date{
        int year, month, day;
    }exp;                           //有効期限
    int price, id, secret;          //値段、カードID、コード
};

int main(void){
    struct preca cards[100];
    struct preca template = {"C-Preca", {2030, 12, 31}, 1000, 0, 0};
    int i, n;

    srand(time(0));                 //擬似乱数発生器に種を与える
    printf("発行するカードの枚数？ ");
    scanf("%d", &n);
    for (i = 0 ; i < n; i++){
        cards[i] = template;        //共通部分は代入で入れる
        cards[i].id = i + 1;        //カードIDは1からとする
        cards[i].secret = rand() % 10000;   //0000～9999を生成 
    }
    for (i = 0; i < n; i++){
        printf("%s #%d: %d円 有効期限%04d/%02d/%02d コード%04d\n",
                cards[i].name, cards[i].id, cards[i].price,
                cards[i].exp.year, cards[i].exp.month, cards[i].exp.day,
                cards[i].secret);
    }
    return 0;
}
