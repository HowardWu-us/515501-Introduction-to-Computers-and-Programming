#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* next_per(char S[1000]) {
    const int N = strlen(S);
    int nd = N-1;
    while(nd-1>=0 && S[nd-1]>=S[nd])nd--;
    if(nd==0) return NULL;

    int jb = N-1;
    for(int i=nd;i<N;++i) {
        if(S[i]<=S[nd-1]) break;
        jb = i;
    }
    // printf("nd:%d, jb:%d\n", nd, jb);
    char tmp = S[nd-1];
    S[nd-1] = S[jb];
    S[jb] = tmp;

    int l=nd;
    int r = N-1;
    while(l<r) {
        char tmp = S[l];
        S[l] = S[r];
        S[r] = tmp;
        l++, r--;
    }

    return S;
}
int cmp(const void *a, const void *b) {
    int na = *(int *)a;
    int nb = *(int *)b;
    return na < nb ? -1 : 1;
}
int main() {
    char T[1000];
    scanf("%s", T);
    for(int nd=0;nd<strlen(T)*strlen(T);++nd) {

    for(int i=0;i<strlen(T)-1;++i) {
        if(T[i]>T[i+1]) {
            char tmp=T[i];
            T[i] = T[i+1];
            T[i+1] = tmp;
        }
    }
    }
    // printf("%s\n\n", T);
    int cn=0;
    do {
        printf("%s ", T);
        if(next_per(T)==NULL)
            break;
    } while(T!=NULL);
    return 0;
}
