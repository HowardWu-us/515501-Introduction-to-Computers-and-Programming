#include <stdio.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) {
    int a_ = *(int *)a;
    int b_ = *(int *)b;
    if((a_%2+2)%2 != (b_%2+2)%2) {
        return a_%2 ? 0 : 1;
    }
    else if((a_%2+2)%2) {
        return b_ < a_ ? 0 : 1;
    }
    else {
        return a_ < b_ ? 0 : 1;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    int arr[1002];
    for (int i = 0; i < T; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, T, sizeof(int), cmp);
    for(int i=0;i<T;++i) {
        printf("%d", arr[i]);
        printf("%c", "\n "[i!=T-1]);
    }
    return 0;
}
