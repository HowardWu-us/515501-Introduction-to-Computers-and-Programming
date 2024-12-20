#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define dpd 1000000000000000000
#define dpi 18
#define min(i, j) (((i) < (j)) ? (i) : (j))
#define max(i, j) (((i) > (j)) ? (i) : (j))
typedef long long int lli;

struct BigInt {
    lli *digits;
    int length;
};
struct BigInt createBigInt(lli x) {
    struct BigInt result;
    result.digits = (lli *)malloc(1 * sizeof(lli));
    result.digits[0] = x;
    result.length = 1;
    return result;
}
struct BigInt createBigIntFromStr(char *str) {
    int len = strlen(str);
    int length = (len + 17) / 18;
    lli *digits = (lli *)malloc(length * sizeof(lli));
    for(int i=0;i<length;++i) {
        digits[i] = 0;
        int pos = max(len - (i+1)*dpi, 0);
        for(int j=0;j<min(len-i*dpi, 18);++j) {
            int idx = pos + j;
            digits[i] = digits[i] * 10 + (str[idx] - '0');
        }
    }

// 1 2 3 4 5 6 7 8 9 10 11 12
// len - (i+1)*18
    struct BigInt result;
    result.digits = digits;
    result.length = length;

    return result;
}
struct BigInt addBigInts(struct BigInt a, struct BigInt b) {
    int maxLength = a.length > b.length ? a.length : b.length;
    lli *resultDigits = (lli *)malloc((maxLength + 1) * sizeof(lli));
    int carry = 0;

    for(int i=0;i<maxLength;++i) {
        lli digitA = (i < a.length) ? a.digits[i] : 0;
        lli digitB = (i < b.length) ? b.digits[i] : 0;

        lli sum = digitA + digitB + carry;
        resultDigits[i] = sum % dpd;
        carry = sum / dpd;
    }

    resultDigits[maxLength] = carry;
    
    struct BigInt result;
    result.digits = resultDigits;
    result.length = maxLength + (carry ? 1 : 0);

    return result;
}
struct BigInt subtractBigInts(struct BigInt a, struct BigInt b) { // only support a >= b
    lli *resultDigits = (lli *)malloc(a.length * sizeof(lli));
    int borrow = 0;

    for(int i=0;i<a.length;++i) {
        lli digitA = a.digits[i];
        lli digitB = (i < b.length) ? b.digits[i] : 0;

        lli diff = digitA - digitB - borrow;
        if(diff < 0) {
            diff += dpd;
            borrow = 1;
        } else {
            borrow = 0;
        }
        resultDigits[i] = diff;
    }

    struct BigInt result;
    result.digits = resultDigits;
    result.length = a.length;

    return result;
}
void printBigInt(struct BigInt a) {
    printf("%lld", a.digits[a.length - 1]);
    for(int i=a.length-2;i>=0;--i) {
        printf(" %018lld", a.digits[i]);
    }
    printf("\n");
}
int main() {
    // struct BigInt a = createBigIntFromStr("987654321283471923749810");
    
    // struct BigInt b = createBigIntFromStr("123456789174983712923228");
    // // 864197532108488210826582

    struct BigInt a = createBigIntFromStr("1234567890123456789012345872397277189237492837492173842983479823749823749289237492837419283798128472981273896789");
    struct BigInt b = createBigIntFromStr("129174983712923227128749823749283749128374912837419283749123874918237498123729174983712923228");
    struct BigInt c = subtractBigInts(a, b);
    
    printBigInt(c);
     
    return 0;
}