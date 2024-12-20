#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int N, M;
int Map[12][12];
int walked[12][12];
// 我先定義這些常量，之後比較好loop
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const char dc[4] = {'U', 'L', 'R', 'D'};

struct Node {
    int x, y, size;
    char step[120];
};

int main() {
    scanf("%d %d", &N, &M);
    memset(Map, 0, sizeof(Map));
    memset(walked, 0, sizeof(walked));
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=M;++j) {
            scanf("%d", &Map[i][j]);
        }
    }

    struct Node queue[120];
    int b = 0;
    int e = 0;
    queue[e++] = (struct Node){1, 1, 0, ""};

    // 我用BFS的方式實現比較簡單
    int find_answer = 0;
    while(b<e) {
        struct Node now = queue[b++];
        // printf("(%d, %d), %d\n", now.x, now.y, now.size);
        if(Map[now.x][now.y]==7) {
            now.step[now.size] = '\0';
            printf("%d\n%s\n", now.size+1, now.step);
            find_answer = 1;
            break;
        }
        for(int dir=0;dir<4;++dir) {
            int nx = dx[dir] + now.x;
            int ny = dy[dir] + now.y;
            if(!Map[nx][ny]) continue;
            if(walked[nx][ny]) continue;

            // printf("->(%d, %d), %d\n", nx, ny, now.size+1);
            now.step[now.size] = dc[dir];
            walked[nx][ny] = 1;
            struct Node newNode = {nx, ny, now.size+1, ""};
            strcat(newNode.step, strcat(now.step, &dc[dir]));
            queue[e++] = newNode;
        }
    }
    if(!find_answer) {
        puts("-1");
    }
    return 0;
}
/*
10 10
6 1 1 1 1 1 1 1 1 1 
0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 7

10 10
6 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 0 7
*/