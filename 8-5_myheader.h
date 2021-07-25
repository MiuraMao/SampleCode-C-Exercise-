enum{
    MAXBOOKS = 50,      //保持する最大の冊数
    TITLESIZE = 100     //題名を入れる文字列領域の大きさ
};

/*外部変数の参照宣言*/
extern int nbooks;                  //main.cの外部変数との重複は問題ない
extern char *books[MAXBOOKS];       //main.cの外部変数との重複は問題ない
extern int prices[MAXBOOKS];        //main.cの外部変数との重複は問題ない

/*関数プロトタイプ*/
void read_books(void);
void search_books(void);