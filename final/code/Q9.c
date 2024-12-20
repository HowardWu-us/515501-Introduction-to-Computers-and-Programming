#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char S[10000];
int solve() {
    int flag;
    int N = strlen(S);
//1
    flag = 0;
    for(int i=0;i<N;++i) {
        if(isupper(S[i])) flag = 1;
    }
    if(flag==0) return 0;

//2
    flag = 0;
    if(islower(S[0])||islower(S[N-1])) return 0;
    for(int i=1;i<N-1;++i) {
        if(islower(S[i])) flag++;
    }
    if(flag < 2) return 0;

//3
    flag = 0;
    if(isdigit(S[0])||isdigit(S[N-1])) return 0;
    for(int i=1;i<N-1;++i) {
        if(isdigit(S[i])) flag++;
    }
    if(flag ==0 ) return 0;

//4
    flag = 0;
    for(int i=0;i<N;++i) {
        if(S[i]=='@') flag++;
        if(S[i]=='!') flag++;
        if(S[i]=='%') flag++;
        if(S[i]=='&') flag++;
        if(S[i]=='*') flag++;
    }
    if(flag ==0 ) return 0;

//5 
    if(strlen(S)<8) return 0;


    return 1;
}
int main() {
    while(fgets(S, 10000, stdin)!=NULL) {
        if(S[strlen(S)-1]=='\n')
            S[strlen(S)-1]=0;
        // printf("%d", strlen(S));
        // printf("%d\n", strlen(S));
        if(solve())
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
