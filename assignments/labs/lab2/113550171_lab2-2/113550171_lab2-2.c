#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int answer = 0;
    while(T--) {
        int x;
        scanf("%d", &x);
        if(x >= 65) {
            answer += 300;
        }
        else if(x > 18) {
            answer += 700;
        }
        else if(x >= 12) {
            answer += 550;
        }
        else {
            answer += 350;
        }
    }
    printf("%d\n", answer);
    return 0;
}