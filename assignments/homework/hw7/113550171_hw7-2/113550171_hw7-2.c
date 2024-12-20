#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1024
// 不知道為什麼會runtime error不過用動態記憶體就過了
char *arr[N + 4];

void reverse(char *S) {
    int len = strlen(S);
    for (int i = 0; i < len / 2; ++i) {
        char temp = S[i];
        S[i] = S[len - i - 1];
        S[len - i - 1] = temp;
    }
}

// 上次的duel
int duel(int left, int right) {
    if (left == right)
        return left;

    int mid = (left + right) / 2;
    int lans = duel(left, mid);
    int rans = duel(mid + 1, right);

    int new_len = strlen(arr[lans]) + strlen(arr[rans]) + 1;
    if (strcmp(arr[lans], arr[rans]) >= 0) {
        arr[lans] = realloc(arr[lans], new_len);
        strcat(arr[lans], arr[rans]);
        reverse(arr[lans]);
        free(arr[rans]);
        return lans;
    } else {
        arr[rans] = realloc(arr[rans], new_len);
        strcat(arr[rans], arr[lans]);
        reverse(arr[rans]);
        free(arr[lans]);
        return rans;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char temp[11];
        scanf("%s", temp);
        arr[i] = malloc(strlen(temp) + 1);
        strcpy(arr[i], temp);
    }
    int winner = duel(0, n - 1);
    printf("%d %s\n", winner, arr[winner]);
    free(arr[winner]);
    return 0;
}