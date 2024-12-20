#include <stdio.h>


int N;
int arr[12];
long long int solve(int x) {
    long long int tmp = 1;
    long long int ans = 0;
    for(int i=N-1;i>=0;--i) {
        ans += arr[i]*tmp;
        tmp *= x;
    }
    return ans;
}
int main() {
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        scanf("%d", &arr[i]);
    }
    int M;
    scanf("%d", &M);
    while (M--)
    {
        int x;
        scanf("%d", &x);
        printf("%lld ", solve(x));
    }
    printf("\n");
    return 0;
}