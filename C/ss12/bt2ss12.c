#include <stdio.h>

void calculate(int a, int b) {
    printf("Cặp số: %d và %d\n", a, b);
    printf("%d * %d = %d\n", a, b, a * b);
    if (a % b == 0) {
        printf("%d / %d = %d\n", a, b, a / b);
    } else if (b % a == 0) {
        printf("%d / %d = %d\n", b, a, b / a);
    } else {
        printf("%d không chia hết cho %d\n", a, b);
    }
}

int main() {
    int a, b, c;
    printf("Nhập vào 3 số a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);

    calculate(a, b);
    calculate(b, c);
    calculate(a, c);

    return 0;
}
