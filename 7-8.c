#include <stdio.h>
//改行文字を取り除く

void chomp(char *);

void chomp(char *p){
    while (*p != '\0'){     //文字列の末尾まで見る
        if (*p == '\n'){    //改行文字を見つけたら
            *p = '\0';      //空文字で上書きしてそこで文字列を終端して
            return;         //戻る
        }
        p++;
    }
    /*空文字がなかったらここで戻る*/
}

int main(void){
    char name[100];

    printf("あなたの名前は？");
    fgets(name, sizeof(name), stdin);
    chomp(name);
    printf("勇者 %s よ、よくぞ参った\n", name);
    return 0;
}
