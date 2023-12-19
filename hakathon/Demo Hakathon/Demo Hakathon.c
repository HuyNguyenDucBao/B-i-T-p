#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void printArray(int arr[], int n) //case 2
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double averagePositive(int arr[], int n) //case 3
{
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
            count++;
        }
    }
    return (double) sum / count;
}

void printIndices(int arr[], int n, int k) //case 4
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            printf("K la phan tu thu %d trong array ", i);
        }
    }
    printf("Khong co phan tu nay");
}


void bubbleSort(int arr[], int n) //case 5
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf ("\n");
}


int countPrimes(int arr[], int n) //case 6
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            count++;
        }
    }
    return count;
}

void sortArray(int arr[], int n) //case 7
{

}

void insertIntoSortedArray(int arr[], int* n, int m) //case 8
{
    int i;
    for (i = *n - 1; (i >= 0 && arr[i] < m); i--)
        arr[i + 1] = arr[i];
    arr[i + 1] = m;
    (*n)++;
}


int main() {
    int arr[MAX], n, choice, k, m;
    do {
        printf("************************MENU**************************\n");
        printf("1. Nhap gia tri n phan tu cua mang (n nhap tu ban phim)\n");
        printf("2. In gia tri cac phan tu trong mang\n");
        printf("3. Tinh trung binh cac phan tu duong (>0) trong mang\n");
        printf("4. In ra vi tri (chi so) cac phan tu co gia tri bang k trong mang (k nhap tu ban phim)\n");
        printf("5. Su dung thuat toan sap xep noi bot sap xep mang giam dan\n");
        printf("6. Tinh so luong cac phan tu la so nguyen to trong mang\n");
        printf("7. Sap xep cac phan tu chan chia het cho 3 o dau mang theo thu tu tang dan, cac phan tu le chia het cho 3 o cuoi mang theo thu tu giam dan, cac phan tu con lai o giua mang theo thu tu tang dan\n");
        printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang (sap xep giam dan) dung vi tri\n");
        printf("9. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap phan tu thu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                printArray(arr, n);
                break;
            case 3:
                printf("Trung binh cac phan tu duong: %.2lf\n", averagePositive(arr, n));
                break;
            case 4:
                printf("Nhap gia tri k: ");
                scanf("%d", &k);
                printIndices(arr, n, k);
                break;
            case 5:
                bubbleSort(arr, n);
                break;
            case 6:
                printf("So luong so nguyen to: %d\n", countPrimes(arr, n));
                break;
            case 7:
                sortArray(arr, n);

                break;
            case 8:
                printf("Nhap gia tri m: ");
                scanf("%d", &m);
                insertIntoSortedArray(arr, &n, m);
                printf("Mang sau khi chen: ");
                printArray(arr, n);
                break;

                break;
            case 9:
                printf("Thoat\n");
                break;
            default:
                printf("Chuc nang khong hop le\n");
                break;
        }
    } while (choice != 9);
    return 0;
}
