#include <stdio.h>
typedef unsigned long long ull;

int N, M;
ull A[15]={1};
ull m(int n) {
    if(n<0) return 0;
    return A[n];
}
ull f(int n) {
    if(n==0) return 0;
    if(n==1) return 0;
    if(n==2) return 1;
    /*
        主要關注在最後兩個人，如果最後兩個是男友，必定成立，所以前面可以隨便填
        如果最後兩個是其他人的話，倒數第三個滿足狀況的也可以算。
        如果最後一個是男友，只要倒數第二個不是男友就好（避免重複算）
        最後 如果倒數第二個是男友，如果倒數第三個是男友則其他隨便填。否則 倒數第四個以前滿足狀況的也可以算
    */
    return   m(n-2)             *1      * 1 //最後兩個是男友、男友
            +f(n-2)             *(M-1)  *(M)//最後兩個是其他人、所有人
            +(m(n-3))   *1      *1      *(M-1)//最後三個是男友、男友、其他人
            +f(n-3)     *(M-1)  *1      *(M-1);//最後三個是其他人、男友、其他人
    
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1;i<15;++i) {
        A[i] = A[i-1]*M;
    }
    // for(int i=1;i<10;++i) {
    //     printf("f(%d)= %llu\n",i , f(i));
    // }
    // for(int i=1;i<10;++i) {
    //     printf("A[%d]= %llu\n",i , A[i]);
    // }
    printf("%llu", f(N));
    return 0;
}