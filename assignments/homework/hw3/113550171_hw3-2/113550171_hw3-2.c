#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N, M;
int Nums[1002];
int dp[1002][2] = {};
bool solve(int pointer, bool ex) {
    if(pointer==N || (ex==0 && pointer==N-1)) {
        return true;
    }
    if(dp[pointer][ex] != 0) {
        return dp[pointer][ex] == 1;
    }
    bool q = false;
    if(abs(Nums[pointer]-Nums[pointer+1])<=M)
        q |= solve(pointer+2, ex);
    if(!q && !ex)
        q |= solve(pointer+1, true);
    dp[pointer][ex] = q ? 1 : -1;
    return q;
}
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i) {
        scanf("%d", &Nums[i]);
    }
    qsort(Nums, N, sizeof(int), cmp);
    if(solve(0, 1-N%2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
