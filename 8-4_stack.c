#include <stdio.h>
//ファイル有効範囲の静的変数（他のファイルにある関数からアクセスできない）

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))  //size_tという符号なし整数型

static int stack[10];                       //スタックのデータを保持する配列
static int sp = -1;                         //スタックポインタ：スタックの「トップ」の添え字を持つ

int push(int item){
    if (sp >= (int)NELEMS(stack)-1){        //配列領域が一杯？、size_t型なのでキャスト
        printf("もう入りません・・・\n");
        return -1;
    }else
        return stack[++sp] = item;          //itemをスタックに積む
}

int pop(void){
    if (sp < 0)                             //データが入っていない？
        return -1;                          //ならば-1を返す
    else
        return stack[sp--];                 //トップのデータを返し、スタックポインタを--する
}