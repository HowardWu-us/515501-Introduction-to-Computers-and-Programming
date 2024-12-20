#include <stdio.h>
#include <string.h>
#include <math.h>


int ans[40321];
int cnt = 0;
int tmp = 0;
void gen(int arr[8], int pos, int x) {
    if(cnt >= (int)(40320))
        return;
    if(pos == 8) {
        ans[cnt++] = x;
    }
    for(int i=7;i>=0;--i) {
        if(arr[i]==1) {
            arr[i]--;
            gen(arr, pos+1, 10*x+i);
            arr[i]++;
        }
    }
}
void key_gen() {

}
void decipher() {

}
double rounde(double x)
{
    return signbit(x) ? ceil(x - 0.5) : floor(x + 0.5);
}
int main(void) {
    int arr[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    gen(arr, 0, 0);
    // printf("%d", ans[100]);
    int templat[7] = {4,2,2,5,6,2,4};
    for(int i=0;i<40320;++i) {
        if(ans[i] == 61340725) {
            int tmp = ans[i];
            ans[i] = ans[0];
            ans[0] = tmp; 
            break;
        }
    }
    
    int x;
    int last = 0;
    int pointer = 0;
    while(scanf("%d", &x)!=EOF) {
        if(x-last>60) {
            if(last != 0) {
            pointer = (pointer+1)%40320;
            last = x;

            } 
        }
        int sdj =100.0*x/60;
        float tim = 1.0*sdj/100;
        printf("%2.2f ", tim);
        int narr[8];
        int t = ans[pointer];
        for(int i=7;i>=0;--i) {
            narr[i] = t%10;
            t/=10;
        }
        for(int i=0;i<8;++i) {
            printf("%d ", narr[i]);
        }
        for(int i=0;i<7;++i) {
            printf("%d", narr[templat[i]]);
        }
    
        printf(" 4225624\n");
    }
    return 0; 
}