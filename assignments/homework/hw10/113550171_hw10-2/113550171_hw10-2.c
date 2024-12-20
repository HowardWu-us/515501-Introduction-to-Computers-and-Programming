#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[25];
    int cnt;
} NameCounter;

int cmp(const void *a, const void *b) {
    NameCounter *na = (NameCounter*)a;
    NameCounter *nb = (NameCounter*)b;
    if(na->cnt == nb->cnt)
        return (strlen(na->name) >= strlen(nb->name))? 0 : 1;
    else
        return (na->cnt < nb->cnt)? 1 : -1;
}
int main() {

    NameCounter NameFrequency[5005];
    int uniqueNameCount = 0;

    char name[25];
    while(scanf("%s", name)!=EOF) { //  輸入的名字
        if(!(isalpha(name[strlen(name)-1]))) {
            name[strlen(name)-1] = 0;
        }

        // 如果名字已經在container裡面，就把該名字數量加一
        // 否則，把名字加入NameFrequency裡面
        bool inContainer = false;
        for(int i=0;i<uniqueNameCount;++i) {
            if(strcmp(NameFrequency[i].name, name)==0) {
                NameFrequency[i].cnt++;
                inContainer = true;
                break;
            }
        }
        if(!inContainer) {
            strcpy(NameFrequency[uniqueNameCount].name, name);
            NameFrequency[uniqueNameCount].cnt = 1;
            uniqueNameCount++;
        }
    }
    // 排序
    qsort(NameFrequency, uniqueNameCount, sizeof(NameCounter), cmp);
    // 輸出
    for(int i=0;i<5;++i) {
        printf("%s %d\n", NameFrequency[i].name, NameFrequency[i].cnt);
    }
    return 0;
}
