#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Hàm kiểm tra số nguyên tố
int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Hàm nhập mảng
void nhapMang(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Nhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Hàm in mảng
void inMang(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm in các phần tử ở góc
void inGoc(int a[MAX][MAX], int n, int m) {
    printf("%d\t%d\n%d\t%d\n", a[0][0], a[0][m-1], a[n-1][0], a[n-1][m-1]);
}

// Hàm in các phần tử trên đường biên
void inBien(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                printf("%d\t", a[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

// Hàm in các phần tử trên đường chéo chính và chéo phụ
void inCheo(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (i == j || i + j == n - 1) {
                printf("%d\t", a[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

// Hàm in các số nguyên tố
void inSNT(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (isPrime(a[i][j])) {
                printf("%d\t", a[i][j]);
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX];
    int n, m;
    printf("Nhap so hang n = ");
    scanf("%d", &n);
    printf("Nhap so cot m = ");
    scanf("%d", &m);

    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(a, n, m);
                break;
            case 2:
                inMang(a, n, m);
                break;
            case 3:
                inGoc(a, n, m);
                break;
            case 4:
                inBien(a, n, m);
                break;
            case 5:
                inCheo(a, n, m);
                break;
            case 6:
                inSNT(a, n, m);
                break;
            case 7:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
