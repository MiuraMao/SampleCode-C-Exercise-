#include <stdio.h>

int main(void){
    int key;
    char plain, cipher;

    printf("平文？");
    scanf("%c", &plain);
    printf("暗号キー？");
    scanf("%d", &key);
    cipher = (plain - 97 + key) % 26 + 97;  //暗号化(aの文字コードは97) %は+や-より優先
    printf("暗号文は「%c」\n", cipher);
    return 0;
}