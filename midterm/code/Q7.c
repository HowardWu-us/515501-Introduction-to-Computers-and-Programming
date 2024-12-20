#include <stdio.h>
#include <string.h>
#include <math.h>
void solve() {
    char st[50];
    scanf("%s", st);
    
    int arr[10] = {0};
    for(int i=0;i<strlen(st);++i) {
        arr[st[i]-'0']++;
    }
    printf("Once occurrence digit:");
    for(int i=9;i>=0;--i) {
        if(arr[i] == 1) {
            printf(" %d", i);
        }
    }
    printf("\n");
}
int main(void) {
    int N;
    scanf("%d", &N);
    while(N--) {
        solve();
    }
    return 0;
}