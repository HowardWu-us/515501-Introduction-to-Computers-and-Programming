#include <stdio.h>
#include <string.h>
#include <math.h>
int solve() {
    char n[50];
    scanf("%s", n);
    
    int arr[10] = {0};
    for(int i=0;i<strlen(n);++i) {
        arr[n[i]-'0']++;
    }
    char m[50];
    scanf("%s", m);
    
    for(int i=0;i<strlen(m);++i) {
        arr[m[i]-'0']--;
    }

    for(int i=0;i<10;++i) {
        if(arr[i]!=0) return 0;
    }
    return 1;
}
int main(void) {
    int N;
    scanf("%d", &N);
    while(N--) {
        if(solve())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}