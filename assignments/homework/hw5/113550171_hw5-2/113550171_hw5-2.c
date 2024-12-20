# include <stdio.h>
#include <stdlib.h>


#define MAX_N ((int)1e6+5)

int **arr;
int capacity[MAX_N];
int pointer[MAX_N];
int s = 0;

// 模仿vector在擴充空間的動作，將空間變成原本的兩倍大
void largerTo(int* vec, int size, int* capacity) {
    if(size >= *capacity) {
        if(*capacity == 0) { // 因為我一開始將capacity設為0（這樣比較好實作），由於無法乘以2，所以乾脆直接申請到2
            *capacity = 1;
        }
        *capacity <<= 1;
        
        vec = (int *)realloc(vec, (*capacity) * sizeof(int));
    }
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    arr = (int **) calloc(N, sizeof(int *));
    for(int i=0;i<N;++i) {
        arr[i] = NULL;
        capacity[i] = 0;
        pointer[i] = 0;
    }

    while(M--) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int a, v;
            scanf("%d %d", &a, &v);
            a--;
            largerTo(arr[a], pointer[a], &capacity[a]);
            arr[a][pointer[a]++] = v;
        } else {
            int a;
            scanf("%d", &a);
            a--;
            if(pointer[a] != 0)
                pointer[a]--;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<pointer[i];j++){
            printf("%d", arr[i][j]);
            if(j != pointer[i] - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}