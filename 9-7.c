#include <stdio.h>
//構造体そのものを引数と戻り値にする

struct complex{
    double real, imag;                  //realが実部、imagが虚部
};

struct complex add_complex(struct complex, struct complex);
struct complex mul_complex(struct complex, struct complex);

struct complex add_complex(struct complex x, struct complex y){
    struct complex tmp;                 //結果を入れる一時変数

    tmp.real = x.real + y.real;
    tmp.imag = x.imag + y.imag;
    return tmp;                         //一時変数の値（構造体丸ごと１つ）を返す
}

struct complex mul_complex(struct complex x, struct complex y){
    struct complex tmp;                 //結果を入れる一時変数

    tmp.real = x.real * y.real - x.imag * y.imag;
    tmp.imag = x.real * y.imag + x.imag * y.real;
    return tmp;                         //一時変数の値（構造体丸ごと１つ）を返す 
}


int main(void){
    struct complex x, y, sum, prod;

    printf("複素数x [a+bi]? ");
    scanf("%lf%lfi", &x.real, &x.imag);
    printf("複素数y [a+bi]? ");
    scanf("%lf%lfi", &y.real, &y.imag);
    sum = add_complex(x, y);            //戻ってきた構造体の値（全メンバの値）をsumに代入
    prod = mul_complex(x, y);           //同上、prodに代入する
    printf("和 %.lf%+.lfi\n", sum.real, sum.imag);
    printf("積 %.lf%+.lfi\n", prod.real, prod.imag);
    return 0;
}
