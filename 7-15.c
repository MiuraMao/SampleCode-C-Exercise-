#include <stdio.h>
//二次元文字配列
//クロスワードパズルのように二次元領域に文字を配置する場合に有用
//文字列へのポインタの配列を使うのが普通

int main(void){
    char tsuki[][15] = {"aoi", "haruma", "yui"};    //15バイトの領域を持つcharの配列（左[]のみ省略可）

    for (int i = 0; i < sizeof(tsuki)/sizeof(tsuki[0]); i++)    //空ポインタで終端を表せない
        printf("%d: %s\n", i, tsuki[i]);
    return 0;
}