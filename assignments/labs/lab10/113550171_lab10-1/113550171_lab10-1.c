#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECK_SIZE 20
#define DRAW 5

#define BASIC 0
#define STAGE1 1
#define STAGE2 2
#define TRAINER 3
void swap(char *a, char *b) {
    char tmp[100];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}
int main(int argc, char *argv[]) {
    // set seed
    int seed = atoi(argv[1]);
    srand(seed);
    
    // 1. Select deck
    char deckName[100];
    printf("Select deck: \n");
    scanf("%s", deckName);

    // 2. Read deck
    FILE *deck = fopen(deckName, "r");
    char cardname[22][100];
    char cardtype[22][100];
    for(int i=0;i<20;++i) {
        fscanf(deck, "%s %s", cardname[i], cardtype[i]);
    }
    fclose(deck);

    // 3. Draw cards
    int dc[5];
    int cnt = 0;
    int tmp;
    while(1) {
        tmp = rand()%20;
        if(strcmp(cardtype[tmp], "basic")==0) {
            dc[cnt++] = tmp;
            break;
        }
    }
    while(1) {
        tmp = rand()%20;
        int flag = 0;
        for(int i=0;i<cnt;++i) {
            if(dc[i] == tmp) flag = 1;
        }
        if(flag) continue;
        dc[cnt++] = tmp;
        if(cnt==5) break;
    }
    
    
    // 4. Print hand cards
    for(int i=0;i<5;++i) {
        printf("%s %s\n", cardname[dc[i]], cardtype[dc[i]]);
    }

    // 5. Save deck
    FILE *afterDraw = fopen("afterDraw.txt", "w");
    for(int i=0;i<20;++i) {
        int flag = 0;
        for(int j=0;j<5;++j) {
            if(dc[j]==i) {
                flag = 1;
            }
        }
        if(flag) continue;
        fprintf(afterDraw, "%s %s\n", cardname[i], cardtype[i]);
    }
    fclose(afterDraw);

    return 0;
}