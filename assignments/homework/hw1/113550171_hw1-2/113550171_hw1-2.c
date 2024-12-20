#include <stdio.h>
#include <math.h>

int main() {
    const int options[6] = {2000, 1000, 500, 100, 10, 1};
    int cnt[6] = {};
    int money, period;
    float rate;
    int money1, money2;

    scanf("$%d,%d %f %d", &money1, &money2, &rate, &period);
    int rmoney = money = money1 * 1000 + money2;
    for (int i = 0; i < 6; i++) {
        cnt[i] = rmoney / options[i];
        rmoney -= cnt[i] * options[i];
    }
    printf("| $2000| $1000| $500| $100| $10| $1|\n");
    printf("|%6d|%6d|%5d|%5d|%4d|%3d|\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5]);
    float monthrate = round(rate/12*100)/100.0;
    // printf("%f\n\n", monthrate);
    printf("Monthly interest rate: %.2f%%\n", rate/12);
    float answer = 1.0*money*(1+rate*period/1200);
    printf("Total loan amount: %.1f\n", answer);
    return 0;
}
