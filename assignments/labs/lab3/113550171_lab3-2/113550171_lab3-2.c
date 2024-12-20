#include <stdio.h>

int min(int a, int b) {
    return a<b?a:b;
}
int max(int a, int b) {
    return a>b?a:b;
}
int main() {
    int N;
    scanf("%d", &N);
    int arr[1002][1002] = {0};
    for(int i=0;i<N;++i) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int j=min(x1, x2);j<=max(x1, x2);++j) {
            for(int k=min(y1, y2);k<=max(y1, y2);++k) {
                arr[j][k]++;
            }
        }
    }
    int max_ans = -1;
    int ans_x, ans_y;
    for(int i=0;i<1002;++i) {
        for(int j=0;j<1002;++j) {
            if(arr[i][j]>max_ans) {
                max_ans = arr[i][j];
                ans_x = i;
                ans_y = j;
            }
        }
    }
    printf("%d %d %d", ans_x, ans_y, max_ans);
    return 0;
}
