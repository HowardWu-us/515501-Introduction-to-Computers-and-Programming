#include <stdio.h>

int main() {
    int Price, Money, Refund, Number;
    scanf("%d %d %d %d", &Price, &Money, &Refund, &Number);

    int bottle = 0;
    int cap = 0;
    int answer = 0;
    while(Money >= Price) {
        // Buy
        bottle += Money/Price;
        cap += Money/Price;
        answer += Money/Price;
        Money %= Price;

        // Exchange
        while(bottle>=Number) {
            int tmp = bottle/Number;
            bottle = bottle%Number + tmp;
            cap += tmp;
            answer += tmp;
        }

        // Change Money
        Money += cap * Refund;
        cap = 0;
    }
    printf("%d\n", answer);
    return 0;
}
