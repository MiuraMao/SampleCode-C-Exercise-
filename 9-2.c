#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//構造体の初期化と代入

struct preca{
    char name[100];         //プリカ名
    int year, month, day;   //有効期限
    int price, id, secret;  //値段、カードID、コード
};

int main(void){
    struct preca template = {"C-Preca", 2030, 12, 31, 1000, 0, 0};  //共通のデータ部分を初期化
    struct preca x, y, z;

    srand(time(0));         //擬似乱数の種を適当に与える
    x = template;           //各メンバの値が代入先へコピー
    x.id = 1;
    x.secret = rand() % 10000;
    printf("%s #%d: %d円, 有効期限%4d/%02d/%02d, コード%04d\n",
            x.name, x.id, x.price, x.year, x.month, x.day, x.secret);
    y = template;
    y.id = 2;
    y.secret = rand() % 10000;
    printf("%s #%d: %d円, 有効期限%4d/%02d/%02d, コード%04d\n",
            y.name, y.id, y.price, y.year, y.month, y.day, y.secret);
    z = template;
    z.id = 3;
    z.secret = rand() % 10000;
    printf("%s #%d: %d円, 有効期限%4d/%02d/%02d, コード%04d\n",
            z.name, z.id, z.price, z.year, z.month, z.day, z.secret);
    return 0;
}