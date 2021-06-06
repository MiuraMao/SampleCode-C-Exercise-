#include <stdio.h>
//パスワードのハッシュ値への変換

int hash(char *);

int hash(char *pw){
    int i;
    long int h;

    h = 0;
    for (i = 0; pw[i] != '\0'; i++)
        h = h * 31 + pw[i];         //この計算はlong intで行われる
    return h % 4093;                //lont intの結果が戻り値の型intに変換される
}

int main(void){
    char pw[100];
    int i, pw_hash, h;

    printf("パスワードを登録して下さい：");
    scanf("%99s", pw);              //入力を99文字に制限
    pw_hash = hash(pw);
    printf("ハッシュ値 %d\n", pw_hash);
    for (i = 0; i < 3; i++){
        printf("パスワード？ ");
        scanf("%99s", pw);          //入力を99文字に制限
        h = hash(pw);
        printf("ハッシュ値 %d\n", h);
        if (h == pw_hash)           //ハッシュ値が一致したら
            break;                  //ループをbreakする
        printf("パスワードが違います\n");
    }
    if (i < 3)                      //ループ条件が成り立っている＝breakしてきた＝ハッシュ値が一致
        printf("ログインしました！\n");
    else                            //ループを回りきった
        printf("ログインに失敗しました...\n");
    return 0;
}