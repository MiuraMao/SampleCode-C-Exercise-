#include <stdio.h>
/*キャストによる型変換*/
/*入力された正の実数の小数点以下第３位を切り捨てて表示*/

int main(void){
    double d, e;

    printf("値？");
    scanf("%lf", &d);
    e = (int)(d * 100) / 100.0;     //100倍してintへキャストし、100を割ることで小数点以下が切り捨て
    printf("%lf\n", e);
}