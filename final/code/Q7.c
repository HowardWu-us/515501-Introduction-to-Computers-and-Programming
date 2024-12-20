// Only get 80 points of 100 points
#include <stdio.h>
#include <stdbool.h>
#define MAX_N 300000000
typedef unsigned long long int ll;


bool isPrime[MAX_N];
int recPrime[MAX_N/10];
ll primeCounter = 0;
int main() {
    int N;
    for(ll i=0;i<MAX_N;++i) {
        isPrime[i] = true;
    }
    for(ll i=2;i<MAX_N;++i) {
        if(isPrime[i]) {
            recPrime[primeCounter++] = i;
            for(ll j=i*i;j<MAX_N;j+=i) {
                isPrime[j] = false;
            }
            // printf("<%d, %d, %d>\n", i, primeCounter, MAX_N);
        }
    }
    // printf("%llu\n", primeCounter);
    while(scanf("%d", &N)==1) {
        int pri=0;
        while(pri<primeCounter && recPrime[pri]<N) {
            pri++;
        }
        printf("%d\n", pri);
    }
    return 0;
}
