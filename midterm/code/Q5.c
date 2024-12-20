#include <stdio.h>
#include <math.h>

int prime(int x) {
    if(x<=1) return 0;
    for(int i=2;i*i<=x;++i) {
        if(x%i == 0) return 0;
    }
    return 1;
}
int main(void) {
    int N;
    scanf("%d", &N);
    printf("Results:");
    for(int i=2;i<N;++i) {
        if(prime(i))
            printf(" %d", i);
    }
    printf("\n");
    return 0;
}