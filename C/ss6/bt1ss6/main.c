#include <stdio.h>

int main() {
    int n, i;
    printf("Nhap so n (1 <= n <= 9): ");
    scanf("%d", &n);
    printf("Bang cuu chuong cua %d:\n", n);
    for(i = 1; i <= 10; ++i) {
        printf("%d x %d = %d\n", n, i, n*i);
    }
    printf("\nBang cuu chuong tu 1 den 9:\n");
    for(n = 1; n <= 9; ++n) {
        printf("Bang cuu chuong cua %d:\n", n);
        for(i = 1; i <= 10; ++i) {
            printf("%d x %d = %d\n", n, i, n*i);
        }
        printf("\n");
    }

    return 0;
}
