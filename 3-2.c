#include <stdio.h>

int main(void){
    int n, score, gp, cred;     //科目数、テストの点数、成績評価点、単位数
    int credits;                //単位数の総和
    double wgps;                //成績評価点の加重和

    printf("科目数？");
    scanf("%d", &n);

    wgps = 0;
    credits = 0;
    for (int i = 1; i <= n; i++){
        printf("科目%dの点数？", i);
        scanf("%d", &score);
        if (score >= 90)
            gp = 4;
        else if (score >= 80)
            gp = 3;
        else if (score >= 70)
            gp = 2;
        else if (score >= 60)
            gp = 1;
        else
            gp = 0;
        printf("科目%dの単位数？", i);
        scanf("%d", &cred);
        credits += cred;        //単位数を累加
        wgps += gp * cred;      //加重和を求めていく
    }
    printf("GPA %.3f\n", wgps / credits);   //GPA = 加重和 / 総単位数
    return 0;

}