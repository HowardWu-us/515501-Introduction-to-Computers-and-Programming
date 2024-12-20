#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char ch[100];
        scanf("%s", ch);
        int answer[10] = {0};
        for(int i=0;i<strlen(ch);++i) {
            answer[ch[i]-'0']++;
        }
        int flag = 0;
        int al[10];
        int cnt = 0;
        for(int i=0;i<10;++i) {
            if(answer[i]>1) {
                al[cnt++] = i;
            }
        }
        if(cnt == 0) {
            printf("No repeated digits found!\n");
        } else {
            printf("%d", al[0]);
            for(int i=1;i<cnt;++i) {
                printf(" %d", al[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
