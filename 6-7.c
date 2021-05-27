#include <stdio.h>
//所要時間で経路をソートする

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

void calc_ttime(int *[], int []);
void show_routes(int *[], int []);

/*各経路の所要時間を計算する*/
void calc_ttime(int *routep[], int ttimep[]){   //評価の際にポインタのポインタになる
    while (*routep != NULL){                    //空ポインタが見つかるまで
        *ttimep = 0;
        for (int *p = *routep; *p > 0; p++)
            *ttimep += *p;                     //乗車時間を所要時間に足し込む
        routep++;
        ttimep++;
    }
}

/*経路の一覧を表示する*/
void show_routes(int *routep[], int ttimep[]){
    for (int **rp = routep; *rp != NULL; rp++, ttimep++){
        printf("経路#%d:", (int)(rp-routep)+1);      //rp-routepが添え字、ptrdiff_t型（ポインタ同士の減算、符号付き整数型）
        for (int *p = *rp; *p > 0; p++)
            printf(" %d分", *p);
        printf(", 合計%d分\n", *ttimep);
    }
}

int main(void){
    int route1[] = {5, 35, 6, -1},
        route2[] = {6, 9, 20, 5, -1},
        route3[] = {20, 35, -1},
        route4[] = {7, 19, 18, 5, -1},
        route5[] = {33, 21, -1};
    int *routes[] = {route1, route2, route3, route4, route5, NULL};     //ポインタ配列
    int ttime[NELEMS(routes)-1];                //各経路の所要時間
    int n = NELEMS(ttime);                      //経路数（ソートのため）

    calc_ttime(routes, ttime);                  //所要時間を計算してttimeに入れる
    show_routes(routes, ttime);                 //一覧を表示

    printf("時間順にします\n");
    /*バブルソート*/
    for (int i = 0; i < n-1; i++){              //iは０から１つずつ増やす
        for (int j = n-2; j >= i; j--){         //後ろから逆順にiまで
            if (ttime[j] > ttime[j+1]){         //隣り合った２つで
                int d, *rp;                     //前が小さくなるように入れ替える
                d = ttime[j]; ttime[j] = ttime[j+1]; ttime[j+1] = d;
                rp = routes[j]; routes[j] = routes[j+1]; routes[j+1] = rp;
            }      
        }           //内側のループによってi以降で最小の要素がiのところにくる
    }               //iを増やしつつ最後まで繰り返せば小さい順に並ぶ

    show_routes(routes, ttime);     //結果を表示
    return 0;
}
