#include <stdio.h>

enum { NCELL = 31 };                    //セル数

void show(char *);

/*状態を１行で表示する*/
void show(char *p){
    for (int i = 0; i < NCELL; i++)
        printf("%c", p[i] ? '0' : '.');
    printf("\n");
}

int main(void){
        char cell[2][NCELL] = {{0}};        //交互に使う２つの配列；セルはすべて０で初期化
        char *curp = cell[0], *nextp = cell[1]; //curpが今の状態、nextpが次の状態
        char *tp;                               //入れ替え用の一時変数

        curp[NCELL/2] = 1;                      //真ん中のセル１つだけが１、他は０
        show(curp);                             //最初の状態を表示
        for (int t = 0; t < 10; t++){           //時刻を進めるループ
            nextp[0] = nextp[NCELL-1] = 0;      //端は常にゼロ
            for (int i = 1; i < NCELL - 1; i++){    //端を除くセルについて
                char curstat, nextstat, *tmpp;
                /*ビットに関する演算子を使って、近傍を３桁の２進数に組む*/
                curstat = curp[i-1] << 2 | curp[i] << 1 | curp[i+1];
                switch (curstat){       //ルールに従ってこのセルの次の状態を決める
                    case 0: case 2: case 5: case 7: nextstat = 0; break;
                    default: nextstat = 1; break;
                }
                nextp[i] = nextstat;
            }
            /*ここまででnextpに次の時刻の状態ができる*/
            tp = curp; curp = nextp; nextp = tp;    //curpとnextpを入れ替える
            show(curp);         //現在の状態を表示
        }
        return 0;
}