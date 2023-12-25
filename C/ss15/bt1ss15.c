#include <stdio.h>
#include <stdbool.h>

bool isFibonacci(int n) {
    int x = 0, y = 1, z = 1;
    if (n == x || n == y)
        return true;
    while (z < n) {
        x = y;
        y = z;
        z = x + y;
    }
    return n == z;
}
int main() {
    int rows, cols;
    printf("Nhap so dong: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    int a[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Cac so fibonacci: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isFibonacci(a[i][j]))
                printf("%d ", a[i][j]);
        }
    }
    return 0;
}
