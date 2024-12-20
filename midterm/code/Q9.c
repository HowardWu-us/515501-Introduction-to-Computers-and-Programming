#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
    char c;
    int arr[10] = {0};
    while(scanf("%c", &c)!=EOF) {
        arr[c-'0']++;
    }
    for(int i=9;i>=0;--i) {
        for(int j=0;j<arr[i];++j)
            printf("%d", i);
    }
    printf("\n");
    return 0;
}