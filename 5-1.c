#include <stdio.h>

int main(void){
    int a[10];              //a[0]が１合目の高さ、a[9]が山頂の高さ
    int i;

    printf("登ります！\n");
    for (i = 0; i < 10; i++){
        if (i < 9)
            printf("%d合目の標高？", i+1);      //添え字に+1したのが合目
        else
            printf("山頂の標高？");
        scanf("%d", &a[i]);
    }
    printf("下ります\n");
    for (i = 9; i >= 0; i--){
        if (i == 9)
            printf("山頂：%d m\n", a[i]);
        else
            printf("%d合目：%d m\n", i+1, a[i]);    //(i+1)合目の高さがa[i]
    }
    printf("無事下山しました！\n");
    return 0;
}