#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))



char A[400], B[400], C[400];
// 接收數字，沒有逗號
char* getint() {
    static char buf[350];
    int pointer = 0;
    char c;
    while((c=getchar()) && c!='@') {
        if(c==',') continue;
        buf[pointer++] = c;
    }
    buf[pointer] = '\0';
    return buf;
}
// 重複
char* repeated_string(char* S, int x) {
    const int len = strlen(S);
    static char T[350];
    for(int r=0;r<=x;++r) {
        strncpy(T+len*r, S, len);
    }
    T[len*x] = '\0';
    return T;
}
// 反轉
char* reversed(char* S) {
    const int len = strlen(S);
    static char T[350];
    for(int i=0;i<len;++i) {
        T[i] = S[len-i-1];
    }
    T[len] = '\0';
    return T;
}
int main() {
    int x;
    strcpy(A, getint());
    scanf("%d\n", &x);
    strcpy(A, repeated_string(A, x));
    for(int i=strlen(A)-1;i>0;--i) {
        if(A[i]=='0') {
            A[i] = '\0';
        } else {
            break;
        }
    }

    strcpy(B, getint());
    scanf("%d\n", &x);
    strcpy(B, repeated_string(B, x));
    for(int i=strlen(B)-1;i>0;--i) {
        if(B[i]=='0') {
            B[i] = '\0';
        } else {
            break;
        }
    }

    strcpy(A, reversed(A));
    strcpy(B, reversed(B));
    const int a_len = strlen(A);
    const int b_len = strlen(B);

    int pointer = 0;
    int carry = 0;
    while(pointer<=max(a_len, b_len)) {
        int ta = (pointer<a_len) ? (A[pointer]-'0') : 0;
        int tb = (pointer<b_len) ? (B[pointer]-'0') : 0;

        A[pointer] = (ta+tb+carry)%10+'0';
        // printf("pos %d: to %d, carry: %d\n", pointer, A[pointer]-'0', carry);
        carry = (ta+tb+carry)/10;
        pointer++;
    }
    pointer -= 1;
    if(A[pointer]!='0') {
        A[pointer+1] = '\0';
    } else {
        A[pointer] = '\0';
    }

    const int final_len = strlen(A);
    for(int i=1;i<=final_len;++i) {
        if(final_len%i) continue;
        int flag = 1;
        for(int j=0;j<final_len/i;++j) {
            if(strncmp(A, A+j*i, i)) {
                flag = 0;

            }
        }
        if(flag) {
            A[i] = '\0';
            for(int j=strlen(A)-1;j>=0;--j) {
                putchar(A[j]);
                if(j%3==0 && j!=0) putchar(',');
            }
            printf("@%d\n", final_len/i);
            exit(0);
        }
    }
    /*
    strcpy(A, getint());
    scanf("%d\n", &x);
    printf("%s\n%d\n", A, x);
    */
    return 0;
}
