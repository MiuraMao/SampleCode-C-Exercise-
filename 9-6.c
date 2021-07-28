#include <stdio.h>
#include <string.h>

struct student{
    int id;
    char name[100];
};

void read_student(struct student *);

void read_student(struct student *p){
    char *q;

    printf("氏名？ ");
    fgets(p->name, sizeof(p->name), stdin);
    /*改行文字を取り除く*/
    if ((q = strchr(p->name, '\n')) != NULL)    //アドレスを返す
        *q = '\0';
    printf("学生番号？ ");
    scanf("%d", &p->id);
}

int main(void){
    struct student x;

    read_student(&x);       //xへのポインタを引数として渡す
    printf("学生番号%d 氏名: %s\n", x.id, x.name);
    return 0;
}