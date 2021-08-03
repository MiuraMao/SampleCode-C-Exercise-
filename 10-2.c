#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//行単位のファイル入力

#define MEIBOFILE "meibo.txt"       //名簿ファイル名
enum{                               //オブジェクト形式マクロでも良い
    NAMESIZE = 55+1,                //氏名の最大文字数 + 空文字分１バイト
    MEIBOSIZE = 100,                //名簿の最大人数
    LINEBUFSIZE = 1024,             //ファイルから１行読むバッファの大きさ（最後に「,」があるが規格によってはエラー）
};

struct student{
    int id;                         //学生番号
    char name[NAMESIZE];            //氏名
};

int read_meibo(struct student *, int);

int read_meibo(struct student *people, int n){      //nは最大人数
    FILE *fp;                                       //入力ストリーム
    char buf[LINEBUFSIZE], *p, *name;               //bufは入力バッファ
    int i;

    if ((fp = fopen(MEIBOFILE, "r")) == NULL){      //名簿ファイルを開く
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL){    //名簿の各行について（fgetsはファイルの終わりに空ポインタを返す）
        if ((p = strchr(buf, '\n')) != NULL)        //改行文字を除去し
            *p = '\0';
        if ((p = strchr(buf, ',')) == NULL){        //コンマを探す
            fprintf(stderr, "変なデータです：%s\n", buf);
            continue;                               //コンマが無ければ変な行なので無視
        }
        name = p + 1;                               //コンマの次から氏名、ポインタnameで指しておく
        *p = '\0';                                  //コンマを空文字でつぶす；bufが学生番号になる（終端文字）
        people[i].id = atoi(buf);                   //構造体に学生番号を入れる
        strncpy(people[i].name, name, NAMESIZE-1);  //氏名を入れる
        people[i].name[NAMESIZE-1] = '\0';          //長すぎた場合のため
        if (++i >= n)                               //ループを終了
            break;
    }
    fclose(fp);
    return i;                                       //読み込んだ項目数を返す
}

int main(void){
    struct student poeple[MEIBOSIZE];               //名簿データを読み込む配列
    int n;

    n = read_meibo(poeple,MEIBOSIZE);               //名簿を読み込む：読み込んだ項目数をnに
    for (int i = 0; i < n; i++)
        printf("[%d] %s\n", poeple[i].id, poeple[i].name);      //各項目を表示
    return 0;
}