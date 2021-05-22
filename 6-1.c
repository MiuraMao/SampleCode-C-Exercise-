#include <stdio.h>

int main(void){
    int i = 5;
    int *p;         //intへのポインタを入れる変数

    p = &i;         //iへのポインタをpに入れる
    printf("i = %d, &i = %p, p = %p, *p = %d\n", i, (void *)&i, (void *)p, *p);
    *p = *p + 1;    //pが指す先（iの領域）に1を足す
    printf("i = %d, &i = %p, p = %p, *p = %d\n", i, (void *)&i, (void *)p, *p);
    return 0;
}