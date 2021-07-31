#include <stdio.h>
#include <stdlib.h>
//文字単位のファイル操作

int main(void){
    char src[1024], dst[1024];          //srcがコピー元、dstがコピー先のファイル名
    FILE *ifp, *ofp;                    //コピー元ストリーム、コピー先ストリーム
    int c;                              //fgetcの戻り値はint型（EOFが返る）

    printf("コピー元？ ");
    scanf("%s", src);
    if ((ifp = fopen(src, "r")) == NULL){   //コピー元を読み取りでオープン
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    printf("コピー先？ ");
    scanf("%s", dst);
    if ((ofp = fopen(dst, "w")) == NULL){   //コピー先を書き込みでオープン
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    /*１文字ずつファイルをコピー*/
    while ((c = fgetc(ifp)) != EOF)     //入力ストリームから１文字ずつ呼んで（getcharと同様）
        fputc(c, ofp);                  //putcharと同様
    fclose(ofp);
    fclose(ifp);
    return 0;
}