#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char A[2000];
    int cnt=0;
    char C[2000];
    while(scanf("%s", C)!=EOF) {
        for(int i=0;i<strlen(C);++i) {
            if(isalnum(C[i])) {
                A[cnt++] = tolower(C[i]);
            }
        }
    }
    int flag = 0;
    for(int i=0;i<cnt;++i) {
        if(A[i]!=A[cnt-i-1]) {
            flag = 1;
            break;
        }
    }
    A[cnt] = 0;
    // printf("%s\n", A);
    if(flag==0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
