#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct egoist {
    char name[50];
    int speed;
    int defense;
    int pass;
    int dribble;
    int shoot;
    int offense;
    int rank;
};
int N;
struct egoist players[37];
int cmp(const void* a, const void* b) {
    struct egoist na = *(struct egoist*)a;
    struct egoist nb = *(struct egoist*)b;

    if((na.shoot+na.offense) != (nb.shoot+nb.offense)) {
        return (na.shoot+na.offense) > (nb.shoot+nb.offense) ? -1 : 1;
    } else if((na.pass+na.dribble+na.offense) != (nb.pass+nb.dribble+nb.offense)) {
        return (na.pass+na.dribble+na.offense) > (nb.pass+nb.dribble+nb.offense) ? -1 : 1;
    } else if((na.speed+na.dribble) != (nb.speed+nb.dribble)) {
        return (na.speed+na.dribble) > (nb.speed+nb.dribble) ? -1 : 1;
    } else if((na.defense+na.pass) != (nb.defense+nb.pass)) {
        return (na.defense+na.pass) > (nb.defense+nb.pass) ? -1 : 1;
    } else if((na.defense+na.speed) != (nb.defense+nb.speed)) {
        return (na.defense+na.speed) > (nb.defense+nb.speed) ? -1 : 1;
    } else if((na.defense+na.speed+na.dribble) != (nb.defense+nb.speed+nb.dribble)) {
        return (na.defense+na.speed+na.dribble) > (nb.defense+nb.speed+nb.dribble) ? -1 : 1;
    } else if(na.defense != nb.defense){
        return (na.defense) > (nb.defense) ? -1 : 1;
    } else {
        return (na.rank<nb.rank)?-1:1;
    }
}
struct bluelock_eleven {
    struct egoist CF;    // Center Forward(中鋒)
    struct egoist OMF_1; // Offensive Mid Fielder(攻擊中場)
    struct egoist OMF_2; // Offensive Mid Fielder(攻擊中場)
    struct egoist LWG;   // Left Winger(左邊鋒)
    struct egoist RWG;   // Right Winger(右邊鋒)
    struct egoist DMF;   // Defensive Mid Fielder防守中場
    struct egoist CB_1;  // Center Back(中後衛)
    struct egoist CB_2;  // Center Back(中後衛)
    struct egoist LSB;   // Left Side Back(左邊後衛)
    struct egoist RSB;   // Right Side Back(右邊後衛)
    struct egoist GK;    // Goal Keeper(守門員)
};

void print_bluelock_eleven(struct bluelock_eleven team)
{
    printf("Here is the starting lineup for Team Blue Lock Eleven:\n");
    printf("CF:%s\n", team.CF.name);
    printf("OMF_1:%s\n", team.OMF_1.name);
    printf("OMF_2:%s\n", team.OMF_2.name);
    printf("LWG:%s\n", team.LWG.name);
    printf("RWG:%s\n", team.RWG.name);
    printf("DMF:%s\n", team.DMF.name);
    printf("CB_1:%s\n", team.CB_1.name);
    printf("CB_2:%s\n", team.CB_2.name);
    printf("LSB:%s\n", team.LSB.name);
    printf("RSB:%s\n", team.RSB.name);
    printf("GK:%s\n", team.GK.name);
    printf("The ones to create a new epoch is us at Blue Lock...!");
}
struct bluelock_eleven team;
bool solve() {
    bool visited[37] = {0};
    bool flag;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].offense+players[i].shoot>160) {
            team.CF = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].pass+players[i].dribble>140 && players[i].offense>70) {
            team.OMF_1 = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].pass+players[i].dribble>140 && players[i].offense>70) {
            team.OMF_2 = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].speed+players[i].dribble>140) {
            team.LWG = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].speed+players[i].dribble>140) {
            team.RWG = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].defense+players[i].pass>140) {
            team.DMF = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].defense>80 && (players[i].defense+players[i].speed)>130) {
            team.CB_1 = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].defense>80 && (players[i].defense+players[i].speed)>130) {
            team.CB_2 = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].speed+players[i].defense>140 && players[i].dribble>60) {
            team.LSB = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        // printf("%d %s\n", i, players[i].name);
        if(players[i].speed+players[i].defense>140 && players[i].dribble>60) {
            team.RSB = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    flag = true;
    for(int i=0;i<N;++i) {
        if(visited[i]) continue;
        if(players[i].defense>90 && players[i].speed>70) {
            team.GK = players[i];
            visited[i] = true;
            flag = false;
            break;
        }
    }
    if(flag) return false;
    return true;
}
int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        scanf("%s %d %d %d %d %d %d %d", players[i].name, &players[i].speed, &players[i].defense, &players[i].pass, &players[i].dribble, &players[i].shoot, &players[i].offense, &players[i].rank);
    }
    qsort(players, N, sizeof(struct egoist), cmp);
    for(int i=0;i<N;++i) {
        printf("%s\n", players[i].name);
    }
    if (!solve()) // use your own condition to see if all the 11 positions are ready
    {
        printf("Project Blue Lock is hereby declared a failure. After that, no one knew the whereabouts of Jinpachi Ego…");
    }
    else
    {
        print_bluelock_eleven(team);
    }

    return 0;
}
