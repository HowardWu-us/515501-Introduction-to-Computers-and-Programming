#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int ind(char c, char *delim) {
    int flag = 0;
    for(int j=0;j<strlen(delim);++j) {
        if(c==delim[j]) {
            flag = 1;
            break;
        }
    }
    return flag;
}
char *my_strtok(char *str, char *delim) {
    static char S[2000] = "";
    if(str!=NULL) {
        strcpy(S, str);
    }
    if(strlen(S) == 0) {
        return NULL;
    }

    int offset = 0;
    static char ret[2000];
    int cnt = 0;
    while(offset < strlen(S) && ind(S[offset], delim)) offset++;

    for(int i=offset;i<strlen(S) && !ind(S[i], delim);++i) {
        ret[cnt++] = S[i];
    }
    if(cnt == 0) {
        return NULL;
    }
    char tmp[2000];
    strcpy(tmp, S+offset+cnt);
    strcpy(S, tmp);
    ret[cnt] = 0;
    return ret;
}
char *get_line() {
    static char S[2000];
    do {
        fgets(S, 2000, stdin);
    } while(strlen(S) <= 1);
    int len = strlen(S);
    for(int i=0;i<len-2;++i) {
        S[i] = S[i+1];
    }
    S[len-2] = 0;
    return S;
}
void solve() {
    char *t;
    char A[2000];
    char del[2000];
    strcpy(A, get_line());
    strcpy(del, get_line());
    // printf("{%s\n%s}\n", A, del);
    strcat(A, del);
    t = my_strtok(A, del);
    while(t!=NULL) {
        printf("%s\n", t);
        t = my_strtok(NULL, del);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    int kase = 1;
    while(T--) {
        printf("Test case %d\n", kase++);
        solve();
    }
    return 0;
}
