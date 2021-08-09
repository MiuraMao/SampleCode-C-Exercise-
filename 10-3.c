#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//構造体配列のソート

#define MEIBOFILE "meibo.txt"       //元の名簿ファイル
#define OUTFILE "new_meibo.txt"     //新しく作るファイル名
enum{
    NAMESIZE = 56,                  //氏名メンバのサイズ
    MEIBOSIZE = 100,                //名簿の最大人数
    LINEBUFSIZE = 1024,             //ファイルの１行を読むバッファサイズ
};

struct student{
    int id;                         //学生番号
    char name[NAMESIZE];            //氏名
};

int read_meibo(struct student *, int);
void sort_meibo(struct student *, int);
void write_meibo(struct student *, int);

int read_meibo(struct student *people, int n){      
    FILE *fp;                                       
    char buf[LINEBUFSIZE], *p, *name;               
    int i;

    if ((fp = fopen(MEIBOFILE, "r")) == NULL){      
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL){    
        if ((p = strchr(buf, '\n')) != NULL)        
            *p = '\0';
        if ((p = strchr(buf, ',')) == NULL){        
            fprintf(stderr, "変なデータです：%s\n", buf);
            continue;                               
        }
        name = p + 1;                               
        *p = '\0';                                  
        people[i].id = atoi(buf);                   
        strncpy(people[i].name, name, NAMESIZE-1);  
        people[i].name[NAMESIZE-1] = '\0';          
        if (++i >= n)                               
            break;
    }
    fclose(fp);
    return i;                                       
}

void sort_meibo(struct student *people, int n){
    struct student tmp;             //項目入れ替え用の一時変数

    /*バブルソート*/
    for (int i = 0; i < n-1; i++){
        for (int j = n-2; j >= i; j--){
            if (people[j+1].id < people[j].id){
                tmp = people[j];    //構造体の代入で項目を入れ替え     
                people[j] = people[j+1];
                people[j+1] = tmp;
            }
        }
    }
}

void write_meibo(struct student *people, int n){
    FILE *fp;                       //出力ストリーム

    if ((fp = fopen(OUTFILE, "w")) == NULL){        //新しい名簿ファイルをオープン
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d,%s\n", people[i].id, people[i].name);   //項目を書きだす（ストリーム指定、数値を出力するためfprintf）
    fclose(fp);                     //作ったファイルをクローズ
}

int main(void){
    struct student people[MEIBOSIZE];   //名簿データ
    int n;

    n = read_meibo(people, MEIBOSIZE);  //ファイルから読む；読んだ数をnに
    sort_meibo(people, n);              //peopleの内容を学生番号順にソート
    write_meibo(people, n);             //新しいファイルに書きだす
    return 0;
}