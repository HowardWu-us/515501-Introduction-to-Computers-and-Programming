#include <stdio.h>
typedef long long int ll;


int main() {
    unsigned long long int A;
    unsigned long long int B;
    while(scanf("%llu", &A)!=EOF) {
        int na = 0;
        int nb = 0;

        na = __builtin_popcountll(A);

        B = 0;
        B |= (A&2863311530)>>1;
        B |= (A&1431655765)<<1;

        nb = __builtin_popcountll(A^B);
        
        if(nb<na) {
            int tmp = nb;
            nb = na;
            na = tmp;
        }
        A >>= na;
        A &= (1<<(nb-na+1))-1;
        printf("Number after extracted: %llu\n", A);
    }
    return 0;
}