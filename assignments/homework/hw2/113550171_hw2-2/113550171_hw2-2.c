#include <stdio.h>

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    if(N<S || (N==6 && S==1)) {
        printf("Sad moon festival QQ\n");
        return 0;
    }
    N -= S;
    int answer;
    if(N<=8*S) { // 最多有幾個人可以拿到9個
        int k = N/8;
        int r = N%8;
        if(k<S-1) {
            answer = k;
        } else {
            answer = (r==5 ? k-1 : k);
        }
    } else {
        answer = S-1;
    }
    printf("%d\n", answer);
    return 0;
}
