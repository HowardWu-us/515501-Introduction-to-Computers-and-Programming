#include <stdio.h>


int N, E;
int V[60][60];
int getSum(int a, int b) {
    int s = 0;
    int x = 20+a;
    int y = 20+b;
    for(int i=1;i<=E;++i) {
        if(a-i<0) break;
        s += V[x-i][y];
    }
    for(int i=1;i<=E;++i) {
        if(a+i>=N) break;
        s += V[x+i][y];
    }
    for(int i=1;i<=E;++i) {
        if(b-i<0) break;
        s += V[x][y-i];
    }
    for(int i=1;i<=E;++i) {
        if(b+i>=N) break;
        s += V[x][y+i];
    }
    s += V[x][y];
    return s;
}
int main() {
    for(int i=0;i<60;++i) {
        for(int j=0;j<60;++j) {
            V[i][j] = 0;
        }
    }
    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            scanf("%d", &V[i+20][j+20]);
        }
    }
    scanf("%d", &E);
    int ex = 0;
    int ey = 0;
    int maxSum = getSum(0, 0);
    for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            if(maxSum<=getSum(i, j)) {
                ex=i;
                ey=j;
                maxSum = getSum(i, j);
            }
        }
    }
    printf("(%d,%d) %d", ex, ey, maxSum);
    return 0;
}