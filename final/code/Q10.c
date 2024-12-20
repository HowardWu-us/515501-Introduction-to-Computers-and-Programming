#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char A[100000];
char B[100000];
char C[100000];
char S[1000000];
int getN() {
    char tmp[100000];
    if(fgets(tmp, 100000, stdin)==NULL) return 0;
    if(strlen(tmp)<=1) return 0;
    strcpy(A, strtok(tmp, "/"));
    strcpy(B, strtok(NULL, "/"));
    strcpy(C, strtok(NULL, "/"));
    if(C[strlen(C)-1]=='\n') C[strlen(C)-1] = 0;
    return 1;
}
void replace() {
    char newS[1000000]="";
    int last = 0;
    for(int i=0;i<strlen(S);++i) {
        if(i+strlen(B)<=strlen(S) && strncmp(S+i, B, strlen(B))==0) {
            i+=strlen(B)-1;
            strcat(newS, C);
            last = strlen(newS);
        } else {
            newS[last++] = S[i];
            newS[last] = 0;
        }
    }
    strcpy(S, newS);
}
int main() {
    fgets(S, 10000, stdin);
    S[strlen(S)-1] = 0;
    while(getN()) {
        // printf("%s %s %s\n", A, B, C);
        // printf("%s\n", S);
        replace();
        // printf("%s\n", S);
    }
    printf("%s\n", S);
    return 0;
}