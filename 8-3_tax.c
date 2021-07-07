extern double rate;             //別ファイルに定義宣言された外部変数を参照する（参照宣言）

int calctax(int price){
    return price * rate / 100;  //rateはパーセント
}