#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

char* int2string(int x) {
    static char buffer[50];
    sprintf(buffer, "%d", x);
    return buffer;
}
int main() {
    int N;
    int arr[12];
    while(scanf("%d", &N)==1) {
        char ans[600]="";
        for(int i=0;i<N;++i) {
            scanf("%d", &arr[i]);
        }
        bool p = 0;
        for(int i=0;i<N;++i) {
            if(arr[i]==0) continue;
            strcat(ans, (arr[i]>0)?"+":"-");
            if(abs(arr[i])!=1 || i==N-1)
                strcat(ans, int2string(abs(arr[i])));
            if(i<=N-2) {
                strcat(ans, "x");
                if(i<N-2) {
                    strcat(ans, "^");
                    strcat(ans, int2string(N-i-1));
                }
            }
        }
        if(strlen(ans)==0) puts("0");
        else {
            if(ans[0]=='-')putchar('-');
            for(int i=1;i<strlen(ans);++i) {
                if(ans[i]=='-' || ans[i]=='+') {
                    printf(" %c ", ans[i]);
                } else {
                    putchar(ans[i]);
                }
            }
            puts("");
        }
    }
    return 0;
}
