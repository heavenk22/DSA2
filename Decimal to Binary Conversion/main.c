#include <stdio.h>
#define MAX 32

int main() {
    int stack[MAX], top = -1;
    int num, rem;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if(num == 0) {
        printf("Binary number: 0\n");
        return 0;
    }

    while(num > 0) {
        rem = num % 2;
        stack[++top] = rem;
        num = num / 2;
    }

    printf("Binary number: ");

    while(top != -1) {
        printf("%d", stack[top--]);
    }

    printf("\n");

    return 0;
}