#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define DRAW 5

int numCards = 0;

// 定義一個資料結構用於儲存卡片名稱與數量
typedef struct {
    char name[25];
    int cnt;
} Card;
int main(int argc, char *argv[]) {
    // set seed
    int seed = atoi(argv[1]);
    srand(seed);
    // 1. Read own cards
    FILE *f = fopen("OwnCards.txt", "r");
    Card Own[300];
    int OwnCnt = 0;
    while(fscanf(f, "%s %d", Own[OwnCnt].name, &Own[OwnCnt].cnt) != EOF) {
        numCards += Own[OwnCnt].cnt;
        OwnCnt++;
    }
    fclose(f);

    printf("You have %d cards\n", numCards);

    // 2. Select pool
    printf("Select pool: \n");
    char poolName[100];
    scanf("%s", poolName);

    // 3. Read pool cards and percentages
    f = fopen(poolName, "r");
    Card P[300];
    int PCnt = 0;
    while(fscanf(f, "%s %d", P[PCnt].name, &P[PCnt].cnt) != EOF) { // read card name and percentage
        PCnt++;
    }
    fclose(f);

    // 4. Draw new cards
    printf("\nYour new cards are: \n");
    int Pick[100];
    int pointer = 0;
    for(int i=0;i<PCnt;++i) {
        for(int j=0;j<P[i].cnt;++j) {
            Pick[pointer++] = i;
        }
    }
    int dc[5]; // draw cards
    for(int i=0;i<5;++i) {
        dc[i] = Pick[rand()%100];
        printf("%s\n", P[dc[i]].name);
        bool inOwn = false;
        for(int j=0;j<OwnCnt;++j) {
            if(strcmp(Own[j].name, P[dc[i]].name) == 0) {
                Own[j].cnt++;
                inOwn = true;
                break;
            }
        }
        if(!inOwn) {
            strcpy(Own[OwnCnt].name, P[dc[i]].name);
            Own[OwnCnt].cnt = 1;
            OwnCnt++;
        }
    }

    char result[40];
    if(strcmp(poolName, "poolCharizard.txt") == 0) {
        strcpy(result, "CharizardDraw.txt");
    } else if (strcmp(poolName, "poolMewtwo.txt") == 0) {
        strcpy(result, "MewtwoDraw.txt");
    } else if (strcmp(poolName, "poolPikachu.txt") == 0) {
        strcpy(result, "PikachuDraw.txt");
    }

    // 5. Write new own cards
    f = fopen(result, "w");
    for(int i=0;i<OwnCnt;++i) {
        fprintf(f, "%s %d\n", Own[i].name, Own[i].cnt);
    }
    fclose(f);
    return 0;
}
