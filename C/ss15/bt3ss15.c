#include <stdio.h>

int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
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
    int maxPrimes = 0, maxPrimesCol = -1;
    for (int j = 0; j < cols; j++) {
        int primes = 0;
        for (int i = 0; i < rows; i++) {
            if (isPrime(a[i][j]))
                primes++;
        }
        if (primes >= maxPrimes) {
            maxPrimes = primes;
            maxPrimesCol = j;
        }
    }
    printf("Cot %d co nhieu so nguyen to nhat\n", maxPrimesCol);
    printf("So luong so nguyen to o cot %d : %d\n", maxPrimesCol, maxPrimes);
    return 0;
}