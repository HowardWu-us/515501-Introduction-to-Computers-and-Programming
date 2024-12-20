#include <stdlib.h>
#include <stdio.h>   
#include <string.h>
#include "rank.h"

void Insert(Node **Table, int N, int score, char *name) {
    Table[N] = malloc(sizeof(Node));
    Table[N]->name = malloc(strlen(name) + 1);
    strcpy(Table[N]->name, name);
    Table[N]->score = score;
}
void Delete(Node **Table, int N, char *name) {
    // 直接將移除的那一個和最後一格交換
    for(int i=0;i<N-1;++i) {
        if(strcmp(Table[i]->name, name)) continue;
        free(Table[i]->name);
        free(Table[i]);

        Table[i] = Table[N-1];
        break;
    }
}
int cmp(const void *a, const void *b) {
    Node *na = *(Node**)a;
    Node *nb = *(Node**)b;
    if(na->score != nb->score) {
        return (na->score>nb->score) ? 1 : -1; 
    }
    else {
        return -strcmp(na->name, nb->name);
    }
}
int *Top(Node **Table, int N, int x) {
    // 用qsort排序
    qsort(Table, N, sizeof(Node*), cmp);
    int* answer = calloc(x, sizeof(int));
    for(int i=0;i<x;++i) {
        answer[i] = N-1-i;
    }
    return answer;
}