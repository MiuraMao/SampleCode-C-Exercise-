#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//構造体の入れ子

struct date{
    int year, month, day;
};

struct preca{
    char name[100];         //プリカ名
    struct date exp;        //有効期限（expire＝期限切れ）
    int price, id, secret;  //値段、カードID、コード
};

int main(void){
    struct preca x = {"C-Preca", {2030, 12, 31}, 1000, 0, 0};   //入れ子の構造体も初期化

    srand(time(0));
    for (int i = 1; i <= 5; i++){
            x.id = i;
            x.secret = rand() % 10000;
            printf("%s #%d: %d円, 有効期限%4d/%02d/%02d, コード%04d\n",
                    x.name, x.id, x.price, x.exp.year, x.exp.month, x.exp.day, x.secret);
    }
    return 0;
}

//構造体の宣言は以下のようにまとめることができる
//struct preca{
//    char name[100];
//    struct date{
//        int year, month, date;
//    } exp;
//    int price, id, secret;
//};
