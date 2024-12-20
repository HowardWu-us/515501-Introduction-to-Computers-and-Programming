#include <stdio.h>
#include <string.h>
#include <math.h>

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
int main(void) {
    int N=0;
    int x;
    int arr[10500];
    long long int sumd = 0;
    while(scanf("%d", &x)==1 && x!=0) {
        arr[N++] = x;
        sumd += x;
    }

    for(int i=0;i<N;++i) {
        int maxPos = i;
        for(int j=i+1;j<N;++j) {
            if(arr[j]>arr[maxPos]) {
                maxPos = j;
            }
        }
        swap(&arr[i], &arr[maxPos]);
    }
    double median;
    if(N%2) {
        printf("median: %d average: %.2f\n", arr[N/2], 1.0*sumd/N);
    } else {
        median = (1.0*arr[N/2-1]+1.0*arr[N/2])/2;
        printf("median: %.1f average: %.2f\n", median, 1.0*sumd/N);
    }
    return 0; 
}