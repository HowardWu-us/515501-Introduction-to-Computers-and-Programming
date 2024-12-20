#include <stdio.h>

int main() {
    int a, b, c, ra, rb, rc;
    scanf("(%d,%d,%d) (%d,%d,%d)", &a, &b, &c, &ra, &rb, &rc);
    printf("(%d,%d,%d)", a+ra, b+rb, c+rc);
    return 0;
}
