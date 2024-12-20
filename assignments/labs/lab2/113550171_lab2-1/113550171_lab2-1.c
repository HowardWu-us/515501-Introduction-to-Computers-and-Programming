#include <stdio.h>

int main() {
    int num1, num2;
    char c;
    scanf("%d %c %d", &num1, &c, &num2);
    if(c=='/' && num2==0) {
        printf("division by zero error\n");
        return 0;
    }
    int answer;
    switch (c)
    {
    case '+':
        answer = num1 + num2;
        printf("%d\n", answer);
        break;
    case '-':
        answer = num1 - num2;
        printf("%d\n", answer);
        break;
    case '*':
        answer = num1 * num2;
        printf("%d\n", answer);
        break;
    case '/':
        printf("%.2f\n", 1.0*num1 / num2);
        break;
    default:
        break;
    }
    return 0;
}