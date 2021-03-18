#include <stdio.h>

int main(void){
    int i, n, r, p;

    printf("カードは全部で何枚？");
    scanf("%d", &n);
    printf("何枚並べる？");
    scanf("%d", &r);
    p = 1;
    for (i = 0; i < r; i++)
        p *= n--;       //値を得る以外に何か状態変化を起こすことを副作用という
    printf("並べ方は%d通りあります\n", p);
    return 0;
}