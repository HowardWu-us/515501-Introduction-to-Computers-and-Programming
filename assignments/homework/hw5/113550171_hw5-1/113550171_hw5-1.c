#include <stdio.h>


void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 蠻直觀的，將矩陣的上半部與下半部對調
void reverseMat(int mat[1000][1000], int n, int m){
    for(int i=0; i<n/2; i++){
        for(int j=0; j<m; j++){
            swap(&mat[i][j], &mat[n-i-1][m-j-1]);
        }
    }
    if(n%2) {
        for(int j=0; j<m/2; j++){
            swap(&mat[n/2][j], &mat[n/2][m-j-1]);
        }
    }
}

int main(){
    int n, m;
    int mat[1000][1000];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    reverseMat(mat, n, m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
