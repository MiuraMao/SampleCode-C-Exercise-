#include <stdio.h>
#include <unistd.h>
//Fiz Buzz

int is_fizz(int);

int is_fizz(int n){                 //3の倍数なら
    if (n % 3 == 0)                 //Fizz
        return 1;
    while (n > 0){
        if (n % 10 == 3)            //1の位は3か？
            return 1;               //ならば3がつくのでFizz
        n /= 10;                    //1の位を捨てて一桁ずらす
    }
    return 0;
}

int main(void){
    int i, n;

    printf("いくつまで？");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        sleep(1);                   //コンピュータが１秒待つ
        if (is_fizz(i)){            //Fizzか？
            if (i % 5 == 0)         //FizzでさらにBuzzか？
                printf("Fizz Buzz\n");  //ならばFizz Buzz
            else                        //FizzだけどBuzzじゃない
                printf("Fizz\n");       //Fizzを表示
        }else if(i % 5 == 0)            //FizzじゃなくてBuzzか？
            printf("Buzz\n");           //Buzzを表示
        else    printf("%d\n", i);      //数を表示
    }
    return 0;
}