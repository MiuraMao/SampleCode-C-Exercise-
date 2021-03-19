#include <stdio.h>
#include <stdlib.h>

int main(void){
    unsigned int seed;
    int x;

    printf("種？");
    scanf("%u", &seed);
    srand(seed);
    while((x = rand() % 10 + 1) != 1)
        printf("%d等です！\n", x);
    printf("１等大当たり！\n");
    return 0;
}