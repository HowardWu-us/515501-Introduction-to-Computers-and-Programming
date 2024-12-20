#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int toint(int a, int b, int c) {
    int ret  = 0;
    ret += 365*(a-2021);
    for(int i=0;i<b;++i) {
        ret += month[i];
    }
    for(int i=1;i<c;++i) {
        ret += 1;
    }
    return ret;
}
int main() {
    // printf("%d\n", toint(2021, 2, 1));
    char S[100];
    int a, b, c;
    scanf("%s", S);
    if(strncmp(S, "ROC", 3)==0) {
        scanf("%s", S);
        sscanf(S, "%d/%d/%d", &a, &b, &c);
        a += 1911;
    }
    else {
        sscanf(S, "%d/%d/%d", &a, &b, &c);
    }
    char *sd[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November",  "December"};
    char *da[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    printf("%s %02d, %d (%s)\n", sd[b-1], c, a, da[toint(a, b, c)%7]);
    // printf("%d %d %d", a, b, c);
    return 0;
}
