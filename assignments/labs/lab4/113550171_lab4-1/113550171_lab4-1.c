#include <stdio.h>
#include <stdlib.h>


int main() {
    long long int C[20];
    C[0] = 1;
    for(int i=1;i<20;++i) {
        C[i] = 0;
        for(int j=0;j<i;++j) {
            C[i] += C[j] * C[i-j-1];
        }
    }
    int N;
    scanf("%d", &N);
    printf("%lld\n", C[N]);
    return 0;
}
