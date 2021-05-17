#include <stdio.h>

enum { NMAX = 100};             //リンゴの最大個数

int main(void){
    int i, n, grams, apple[NMAX];

    n = 0;
    printf("重さを入力して下さい（０で終了）\n");
    while (n < NMAX){
        printf("重さ？");
        scanf("%d", &grams);
        if (grams == 0)         //0が入力されたら
            break;              //入力終了
        apple[n++] = grams;
    }
    /*選択ソートで整列*/
    for (i = 0; i <= n-2; i++){     //iを0から1ずつ増やしながら
        int min = i, tmp;
        for (int j = i+1; j < n; j++){      //i以上の添え字の要素の中で
            if (apple[j] < apple[min])      //一番小さいものの添え字を
                min = j;                    //minに求める
        }
        tmp = apple[i];         //一次変数tmpを使って
        apple[i] = apple[min];  //apple[i]とapple[min]を入れ替えて
        apple[min] = tmp;       //apple[i]がi以上の部分で最小になるようにする
    }
    /*表示*/
    for (i = 0; i < n; i++)
        printf("%d ", apple[i]);
    printf("\n");
    return 0;
}