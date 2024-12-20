#include <stdio.h>


int N;
int arr[1002];
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main() {
    int t;
    int N=0;
    while(scanf("%d", &t) && t) {
        arr[N++] = t;
    }
    int max_ele = 0;
    for(int i=0;i<N;++i) {
        max_ele = i;
        for(int j=i;j<N;++j) {
            if(arr[j] > arr[max_ele]) max_ele = j;
        }
        swap(&arr[i], &arr[max_ele]);
    }
    for(int i=0;i<N;++i) {
        printf("%d%c", arr[i], " \n"[i==N-1]);
    }
    return 0;
}