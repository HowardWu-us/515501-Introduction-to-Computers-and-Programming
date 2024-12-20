#include <stdio.h>

int main() {
    int T;
    int nums[102];
    scanf("%d", &T);
    for(int i=0;i<T;++i) {
        scanf("%d", &nums[i]);
    }
    int ans = 0;
    for(int i=0;i<T;++i) {
        while(nums[i]) {
            ans++;
            for(int j=i;j<T;++j) {
                if(nums[j] == 0) {
                    break;
                }
                nums[j]--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
