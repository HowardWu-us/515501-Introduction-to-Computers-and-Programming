#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%d %d",&n1, &n2);
    printf("num1=%d, num2=%d in decimal\n", n1, n2);
    printf("num1=%o, num2=%o in octal\n", n1, n2);
    printf("num1=%x, num2=%x in hexadecimal\n", n1, n2);

    printf("(%d)+(%d)=%d\n", n1, n2, n1+n2);
    printf("(%d)-(%d)=%d\n", n1, n2, n1-n2);
    printf("(%d)*(%d)=%d\n", n1, n2, n1*n2); 
    printf("(%d)/(%d)=%d\n", n1, n2, n1/n2);    
    printf("(%d)%(%d)=%d\n", n1, n2, n1%n2);    
    printf("(%d)/(%d)=%.2f\n", n1, n2, 1.0*n1/n2);    
    printf("(%d)/(%d)=%.2e in scientific notation\n", n1, n2, 1.0*n1/n2);    
    
    
    return 0;
}
