#include <stdio.h>

void calculate(int a, int b) {
    printf("Cặp số: %d và %d\n", a, b);
    printf("%d + %d = %d\n", a, b, a + b);
    if (a > b) {
        printf("%d - %d = %d\n", a, b, a - b);
    } else {
        printf("%d - %d = %d\n", b, a, b - a);
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
