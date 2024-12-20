#include <stdio.h>
#include <string.h>


enum Rhythm {
    QUARTER_NOTE = 1,
    HALF_NOTE = 2,
    WHOLE_NOTE = 4
};
enum Note {
    C = 1,
    D = 2,
    E = 3,
    F = 4,
    G = 5,
    A = 6,
    B = 7
};
// 輸出音符
void printNote(char c) {
    enum Note noteValue;
    switch(c) {
        case 'C': {
            noteValue = C;
            break;
        }
        case 'D': {
            noteValue = D;
            break;
        }
        case 'E': {
            noteValue = E;
            break;
        }
        case 'F': {
            noteValue = F;
            break;
        }
        case 'G': {
            noteValue = G;
            break;
        }
        case 'A': {
            noteValue = A;
            break;
        }
        case 'B': {
            noteValue = B;
            break;
        }
    }
    printf("%d ", noteValue);
}
// 輸出節奏
void printRhythm(char* rhythm, int *cnt) {
    enum Rhythm rhythmValue;
    if (strcmp(rhythm, "QUARTER_NOTE") == 0) {
        rhythmValue = QUARTER_NOTE;
    } else if (strcmp(rhythm, "HALF_NOTE") == 0) {
        rhythmValue = HALF_NOTE;
    } else if (strcmp(rhythm, "WHOLE_NOTE") == 0) {
        rhythmValue = WHOLE_NOTE;
    }
    for (int i = 1; i < rhythmValue; i++) {
      printf("- ");
    }
    *cnt += rhythmValue;
}
void solve() {
    char op;
    scanf("%c ", &op);
    int rt=0;
    do {
        if(rt++>10) break;
        int cnt = 0;
        printf("| ");
        while(cnt<4) {
            char c;
            char rhythm[20];
            scanf("%c %s ", &c, rhythm);
            printNote(c);
            printRhythm(rhythm, &cnt);
        }
        scanf("%c", &op);
        op = getchar();
    } while(op==' ');
}
int main() {
    int N;
    scanf("%d\n", &N);
    for(int i=0;i<N;++i) {
        solve();

        // 輸出結尾
        if(i<N-1)
            puts("|");
        else
            puts("||");
    }
    return 0;
}
