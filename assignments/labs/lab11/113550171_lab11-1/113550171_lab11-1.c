#include <stdio.h>
typedef long long int ll;


int main() {
    unsigned long long int answer = 0;
    int x;
    while(scanf("%d", &x)==1) {
        answer = answer|(1ULL << x);
    }
    for(int i=0;i<64;++i) {
        if(answer&(1ULL<<i))
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}