#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void checkArray(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            printf("%d là số nguyên tố\n", arr[i]);
            count++;
        } else {
            printf("%d không phải là số nguyên tố\n", arr[i]);
        }
    }
    printf("Mảng có %d số nguyên tố\n", count);
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 10};

    printf("Kiểm tra mảng a:\n");
    checkArray(a, 5);

    printf("Kiểm tra mảng b:\n");
    checkArray(b, 5);

    return 0;
}
