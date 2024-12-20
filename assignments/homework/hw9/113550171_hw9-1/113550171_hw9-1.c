#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAX_N 1024


typedef struct {
    char name[21];
    int strength;
    int luck;
} Player;
typedef struct{
    char teamName[20];
    int score;
} Beat;
typedef struct{
    char teamName[20];
    int ID;
    Player player[5];
    Beat* history;
    int historySize;
} Team;
Team teams[MAX_N];
void addBeatResultTo(Team *t, Beat result) {
    t->history = realloc(t->history, sizeof(Beat)*(t->historySize+1));
    t->history[t->historySize++] = result;
}
void changeLuck(Team *t, int offset) {
    for(int i=0;i<5;++i) {
        t->player[i].luck = (t->player[i].luck+offset+100)%100;
    }
}
int cmp(Team *a, Team *b, int *oppScore) {
    int aScore = 0;
    int bScore = 0;
    int round = 1;
    while(aScore<3 && bScore<3) {
        int result = 0;
        // 比賽規則
        switch (round) {
        case 1: {
            for(int i=0;i<5;++i) {
                result += a->player[i].strength + a->player[i].luck;
                result -= b->player[i].strength + b->player[i].luck;
            }
            break;
        }
        case 2: {
            result += a->player[0].strength + a->player[0].luck;
            result += a->player[1].strength + a->player[1].luck;
            result += a->player[4].strength + a->player[4].luck;
            result -= b->player[0].strength + b->player[0].luck;
            result -= b->player[1].strength + b->player[1].luck;
            result -= b->player[4].strength + b->player[4].luck;
            break;
        }
        case 3: {
            result += a->player[2].strength + a->player[2].luck;
            result += a->player[3].strength + a->player[3].luck;
            result -= b->player[2].strength + b->player[2].luck;
            result -= b->player[3].strength + b->player[3].luck;
            break;
        }
        case 4: {
            int molesCount = 0;
            for(int i=0;i<5;++i) {
                if(a->player[i].strength<0) molesCount++;
                if(b->player[i].strength<0) molesCount--;
            }
            result = -molesCount;
            break;
        }
        case 5: {
            int aMaxStrength = 0, aMaxLuck = 0;
            int bMaxStrength = 0, bMaxLuck = 0;
            for(int i=0;i<5;++i) {
                aMaxStrength = MAX(aMaxStrength, a->player[i].strength);
                bMaxStrength = MAX(bMaxStrength, b->player[i].strength);
                aMaxLuck = MAX(aMaxLuck, a->player[i].luck);
                bMaxLuck = MAX(bMaxLuck, b->player[i].luck);
            }
            result = aMaxStrength*aMaxLuck - bMaxStrength*bMaxLuck;
            break;
        }
        }
        if(result>=0) {
            changeLuck(a, -5);
            changeLuck(b, 5);
            aScore++;
        } else {
            changeLuck(a, 5);
            changeLuck(b, -5);
            bScore++;
        }
        round++;
    }
    if(aScore==3) {
        *oppScore = bScore;
        return 1;
    } else {
        *oppScore = aScore;
        return -1;
    }
}
int match(int l, int r) {
    if(r-l==1) {
        return l;
    }
    const int m = (l+r)/2;
    // 得到左右隊伍的勝者
    int leftWinner = match(l, m);
    int rightWinner = match(m, r);

    Beat result;
    if(cmp(&teams[leftWinner], &teams[rightWinner], &result.score)>0) {
        strcpy(result.teamName, teams[rightWinner].teamName);
        addBeatResultTo(&teams[leftWinner], result);
        return leftWinner;
    } else {
        strcpy(result.teamName, teams[leftWinner].teamName);
        addBeatResultTo(&teams[rightWinner], result);
        return rightWinner;
    }
}
int main() {
    int N;
    scanf("%d", &N);

    // 輸入隊員資料
    for(int i=0;i<N;++i) {
        char teamName[20];
        int teamID;
        scanf("%s %d", teamName, &teamID);
        teams[teamID-1].ID = teamID;
        strcpy(teams[teamID-1].teamName, teamName);
        teams[teamID].historySize = 0;
        for(int j=0;j<5;++j) {
            Player *cur = &teams[teamID-1].player[j];
            scanf("%s %d %d", cur->name, &cur->strength, &cur->luck);
        }
    }

    // 開始比賽
    int winner = match(0, N);

    // 輸出結果
    printf("%s win from %d teams\n", teams[winner].teamName, N);
    for(int i=0;i<teams[winner].historySize;++i) {
        printf("%s vs %s %d:%d\n",
            teams[winner].teamName,
            teams[winner].history[i].teamName,
            3,
            teams[winner].history[i].score);
    }
    printf("Congratulations to %s, %s, %s, %s, %s for winning the world championship!\n",
        teams[winner].player[0].name,
        teams[winner].player[1].name,
        teams[winner].player[2].name,
        teams[winner].player[3].name,
        teams[winner].player[4].name);
    return 0;
}
