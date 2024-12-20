#include <stdio.h>

int T;
int nums[102];
int solve(int l, int r) {

    int ans = 0;
    for(int i=l;i<r;++i) {
        if(nums[i] == 0) {
            continue;
        }
        for(int j=i;j<r;++j) {
            if(nums[j] == 0) {
                break;
            }
            nums[j]--;
        }
        ans++;
        break;
    }

    for(int i=l;i<r;++i) {
        if(nums[i] == 0) {
            continue;
        }
        int j;
        for(j=i;j<r;++j) {
            if(nums[j] == 0) {
                break;
            }
        }
        ans += solve(i, j);
        i = j;
    }
    return ans;
}
int main() {
    scanf("%d", &T);
    for(int i=0;i<T;++i) {
        scanf("%d", &nums[i]);
    }
    printf("%d\n", solve(0, T));
    return 0;
}
