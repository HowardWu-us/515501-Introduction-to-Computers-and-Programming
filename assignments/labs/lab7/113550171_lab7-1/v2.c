#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int N;
    int arr[12];
    while(scanf("%d", &N)==1) {
        for(int i=0;i<N;++i) {
            scanf("%d", &arr[i]);
        }
        bool p=0;
        for(int i=0;i<N;++i) {
            if(arr[i]==0) continue;
            if(!p) {
                if(i==N-1)
                    printf("%d", arr[i]);
                else {
                    if(abs(arr[i])==1) {
                        if(arr[i]==-1) printf("-");
                    } else {
                        printf("%d", arr[i]);
                    }
                }
            } else {
                if(arr[i] > 0)
                    printf(" + ");
                else
                    printf(" - ");
                if(abs(arr[i])!=1 || i==N-1)
                    printf("%d", abs(arr[i]));
            }
            if(i==N-2) printf("x");
            else if(i<N-2) printf("x^%d", N-i-1);
            p = true;
        }
        if(!p) printf("0");
        puts("");
    }
    return 0;
}