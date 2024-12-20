#include <stdio.h>
#include <stdlib.h>



int main() {
    int N;
    int arr[12];
    while(scanf("%d", &N)==1) {
        int allZero = 1;
        int p=0;
        for(int i=0;i<N;++i) {
            scanf("%d", &arr[i]);
            if(arr[i]) allZero = 0;
        }
        if(N>1 && arr[0]) {
            if(arr[0]==1)
                printf("x");
            else if(arr[0]==-1)
                printf("-x");
            else
                printf("%dx", arr[0]);
            
            if(N-1!=1) {
                printf("^%d", N-1);
            }
            p= 1;
        }
        for(int i=1;i<N-1;++i) {
            if(arr[i]==0) continue;

            if(arr[i] > 0) {
                if(p) printf(" + ");
                
                if(arr[i]==1) {
                    printf("x");
                }
                else  {
                    printf("%dx", arr[i]);
                }
            } else {
                if(p) printf(" - ");
                else printf("-");
                if(arr[i]==-1)
                    printf("x");
                else {
                    if(N-i-1==1) printf("%dx", -arr[i]);
                    else printf("%dx", -arr[i]);
                }
            }
            if(N-i-1!=1)
                printf("^%d", N-i-1);
            p=1;
        }
        if(allZero) {
            printf("0");
        } else if(arr[N-1]) {
            if(p==0) {
                printf("%d", arr[N-1]);
            }
            else if(arr[N-1]>0) {
                printf(" + %d", arr[N-1]);
            }
            else if(arr[N-1]<0) {
                printf(" - %d", -arr[N-1]);
            }
        }
        printf("\n");

    }
    return 0;
}