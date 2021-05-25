#include <stdio.h>

void showadj(float *);

/*関数showadjの定義*/
void showadj(float *p){                 //指定された順位の要素をpが指す
    if (p[-1] < 0)                      //直前の要素はデータの端？
        printf("---------\n");          //pは１位を指すので上に線を引く
    else                                //直前の要素がちゃんとデータなら
        printf("  %.2f秒\n", p[-1]);    //それを表示
          
    printf("* %.2f秒\n", *p);           //pが指す要素を表示

    if (p[1] < 0)                       //直後の要素はデータの端？
        printf("---------\n");          //pは最下位なので下に線を引く
    else                                //直後の要素がちゃんとデータなら
        printf("  %.2f秒\n", p[1]);     //それを表示
}

int main(void){
    float t[] = {-1, 28.89, 29.18, 29.22, 29.66, 30.77, 31.33, -1};
    int i;

    for (i = 1; i < sizeof(t)/sizeof(t[0]) - 1; i++)
        printf("%d位 %.2f秒\n", i, t[i]);
    printf("何位の前後？");
    scanf("%d", &i);
    showadj(&t[i]);     //指定された順位の要素へのポインタを渡す
    return 0;
}