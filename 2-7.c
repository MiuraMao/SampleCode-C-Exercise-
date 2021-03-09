#include <stdio.h>
/*キャストによる型変換*/
/*入力された正の実数の小数点以下第３位を切り捨てて表示*/

int main(void){
    double d, e;

    printf("値？");
    scanf("%lf", &d);
    e = (int)(d * 100) / 100.0;     //intへのキャストで小数点以下が切り捨てられる
    printf("%lf\n", e);
}