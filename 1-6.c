#include <stdio.h>

int main(void){
    int min, max, deg;

    printf("最低温度？");
    scanf("%d", &min);
    printf("最高温度？");
    scanf("%d", &max);

    /*数字を表示*/
    deg = min;
    while(deg <= max){
        printf("%3d ", deg);     //空白を加えて４文字幅で表示
        deg += 10;
    }
    printf("\n");

    /*線を表示*/
    deg = min;
    while(deg <= max){
        printf("--+-");         //数字に合わせて４文字
        deg += 10;
    }
    printf("\n");
    return 0;
}