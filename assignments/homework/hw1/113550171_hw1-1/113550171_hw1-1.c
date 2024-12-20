#include <stdio.h>
int main() {
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);
    printf("Germany: %02d.%02d.%04d\n", day, month, year+1911);
    printf("Belgium: %02d/%02d/%04d\n", day, month, year+1911);
    printf("Taiwan: %04d/%02d/%02d\n", year+1911, month, day);
    printf("US: %02d/%02d/%02d\n", month, day, (year+1911)%100);
    printf("UK: %02d/%02d/%02d\n", day, month, (year+1911)%100);
    return 0;
}
