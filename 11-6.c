#include <stdio.h>
//ハノイの塔（再帰）
void hanoi(int, char, char, char);

void hanoi(int n, char from, char work, char to){
    if (n == 1)                                 //移すのが１枚だけなら
        printf("%d: %c -> %c\n", n, from, to);  //この１枚をfromからtoに移す
    else{                                       //２枚以上あるなら
        hanoi(n-1, from, to, work);             //(n-1)枚をfromからworkに移し
        printf("%d: %c -> %c\n", n, from, to);  //最下の１枚をfromからtoに移し
        hanoi(n-1, work, from, to);             //(n-1)枚をworkからtoに移す
    }
}

int main(void){
    int n;

    printf("円盤の枚数？ ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');                    //A杭からC杭へ移す（B杭は作業用）
    return 0;
}