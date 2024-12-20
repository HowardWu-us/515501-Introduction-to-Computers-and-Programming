#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define ll long long

ll power(ll a, ll b, ll mod) {
    long long result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = ((__uint128_t)result * a) % mod;
        }
        b = b >> 1;
        a = ((__uint128_t)a * a) % mod;
    }
    return result;
}

bool isPrimeFermat(ll n, int iterations) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    for (int i = 0; i < iterations; i++) {
        ll a = 2 + rand() % (n - 3);
        if (power(a, n - 1, n) != 1) {
            return false;
        }
    }
    return true;
}
ll primes[10000000];
int main() {
    srand(time(NULL));
    ll x;
    int k;
    scanf("%lld %d", &x, &k);
    int cnt = 0;
    for(ll i=x-1;i>=2;i--) {
        // fprintf(stderr, "Finding %lld\n", i);
        if(isPrimeFermat(i, 30)) primes[cnt++] = i;
        if(cnt>=k) break;
    }
    printf("Results:");
    for(int i=0;i<cnt;++i) {
        printf(" %lld", primes[cnt-i-1]);
    }
    puts("");
    return 0;
}
