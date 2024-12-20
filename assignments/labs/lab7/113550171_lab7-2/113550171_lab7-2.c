#include <stdio.h>
#include <string.h>
#include <ctype.h>
int read_line(char str[]) {
    int ch, i = 0;
    while (1) { 
        ch = getchar();
        if (ch == '\n' || ch == EOF)
            break;
        if (i < 605)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
int Che(char c, int r) {
    if(islower(c)) {
        return (c-'a'+r)%26+'a'; 
    } else {
        return(c-'A'+r)%26+'A';
    }
}
int main() {
    int N, R;
    scanf("%d", &N);
    char C[605];
    getchar();
    while(N--) {
        read_line(C);
        scanf("%d", &R);
        getchar();
        int n=strlen(C);
        for(int i=0;i<n;++i) {
            if(C[n-1-i]==' ') printf(" ");
            else printf("%c", Che(C[n-i-1], R));
        }
        printf("\n");
    }
    return 0;
}