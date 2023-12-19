#include <stdio.h>
#include <stdlib.h>

// Hàm kiểm tra số nguyên tố (case6)
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

// Hàm sắp xếp mảng theo thuật toán lựa chọn (case5)
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
// Hàm in mảng
void inMang(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");

// Hàm sắp xếp mảng hai chiều theo cột (case5)
        void sortColumns(int **a, int n, int m) {
            int *temp = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++)
                    temp[i] = a[i][j];
                selectionSort(temp, n);
                for (int i = 0; i < n; i++)
                    a[i][j] = temp[i];
            }
            free(temp);
        }

// Hàm sắp xếp đường chéo chính của mảng giảm dần bằng thuật toán nổi bọt (case7)
        void bubbleSortMainDiagonal(int **a, int n) {
            int temp;
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                    if (a[j][j] < a[j + 1][j + 1]) {
                        temp = a[j][j];
                        a[j][j] = a[j + 1][j + 1];
                        a[j + 1][j + 1] = temp;
                    }
        }


//case8
        void chenMang1ChieuVaoMang2Chieu(int **a, int *b, int n, int m, int k) {
            if (k < 0 || k >= n) {
                printf("Chỉ số dòng không hợp lệ.\n");
                return;
            }
            for (int j = 0; j < m; j++)
                a[k][j] = b[j];
        }



        int main() {
            int n, m;
            printf("Nhập số dòng (n): ");
            scanf("%d", &n);
            printf("Nhập số cột (m): ");
            scanf("%d", &m);

            int **a = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++)
                a[i] = (int *)malloc(m * sizeof(int));

            int choice;
            do {
                printf("\n************************MENU**************************\n");
                printf("1. Nhập giá trị các phần tử của mảng\n");
                printf("2. In giá trị các phần tử trong mảng theo ma trận\n");
                printf("3. Tính số lượng các phần tử chia hết cho 2 và 3 trong mảng\n");
                printf("4. In các phần tử và tổng các phần tử nằm trên đường biên, đường chéo chính và đường chéo phụ\n");
                printf("5. Sử dụng thuật toán sắp xếp lựa chọn sắp xếp các phần tử tăng dần theo cột của mảng\n");
                printf("6. In ra các phần tử là số nguyên tố trong mảng\n");
                printf("7. Sử dụng thuật toán nổi bọt sắp xếp các phần tử trên đường chéo chính của mảng giảm dần\n");
                printf("8. Nhập giá trị một mảng 1 chiều gồm m phần tử và chỉ số dòng muốn chèn vào mảng, thực hiện chèn vào mảng 2 chiều\n");
                printf("9. Thoát\n");
                printf("Chọn chức năng: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        // Nhập giá trị các phần tử của mảng
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++) {
                                printf("Nhập a[%d][%d] = ", i, j);
                                scanf("%d", &a[i][j]);
                            }
                        break;
                    case 2:
                        // In giá trị các phần tử trong mảng theo ma trận
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < m; j++)
                                printf("%d ", a[i][j]);
                            printf("\n");
                        }
                        break;
                    case 3:
                        // Tính số lượng các phần tử chia hết cho 2 và 3 trong mảng
                        int count = 0;
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++)
                                if (a[i][j] % 2 == 0 && a[i][j] % 3 == 0)
                                    count++;
                        printf("So luong phan tu chia het cho 2 va 3 trong mang la: %d\n", count);
                        break;
                    case 4:
                        // In các phần tử và tổng các phần tử nằm trên đường biên, đường chéo chính và đường chéo phụ
                        void inDuongBienVaDuongCheo(int **a, int n, int m) {
                            int tong = 0;
                            printf("Cac phan tu nam tren duong bien: ");
                            for (int i = 0; i < n; i++)
                                for (int j = 0; j < m; j++)
                                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                                        printf("%d ", a[i][j]);
                                        tong += a[i][j];
                                    }
                            printf("\nCac phan tu nam tren duong cheo chinh: ");
                            for (int i = 0; i < n; i++)
                                for (int j = 0; j < m; j++)
                                    if (i == j) {
                                        printf("%d ", a[i][j]);
                                        tong += a[i][j];
                                    }
                            printf("\nCac phan tu nam tren duong cheo phu: ");
                            for (int i = 0; i < n; i++)
                                for (int j = 0; j < m; j++)
                                    if (i + j == n - 1) {
                                        printf("%d ", a[i][j]);
                                        tong += a[i][j];
                                    }
                            printf("\nTong cac phan tu nam tren duong bien, duong cheo chinh va duong cheo phu: %d\n", tong);
                        }

                    case 5:
                        // Sử dụng thuật toán sắp xếp lựa chọn sắp xếp các phần tử tăng dần theo cột của mảng
                        sortColumns(a, n, m);
                        printf("Mang sau khi sap xep cac phan tu tang dan theo cot:\n");
                        inMang(a, n, m);
                        break;
                    case 6:
                        // In ra các phần tử là số nguyên tố trong mảng
                        printf("Cac phan tu so nguyen to trong mang la: ");
                        for (int i = 0; i < n; i++)
                            for (int j = 0; j < m; j++)
                                if (isPrime(a[i][j]))
                                    printf("%d ", a[i][j]);
                        printf("\n");
                        break;
                    case 7:
                        // Sử dụng thuật toán nổi bọt sắp xếp các phần tử trên đường chéo chính của mảng giảm dần
                        bubbleSortMainDiagonal(a, n);
                        printf("Mang sau khi sap xep cac phan tu tren duong cheo chinh giam dan:\n");
                        inMang(a, n, m);

                        break;
                    case 8:
                        // Nhập giá trị một mảng 1 chiều gồm m phần tử và chỉ số dòng muốn chèn vào mảng, thực hiện chèn vào mảng 2 chiều
                        int k;
                        printf("Nhap chi so dong muon chen: ");
                        scanf("%d", &k);
                        chenMang1ChieuVaoMang2Chieu(a, b, n, m, k);
                        printf("Mang sau khi chen:\n");
                        inMang(a, n, m);


                        break;
                    case 9:
                        printf("Thoat.\n");
                        break;
                    default:
                        printf("Lua chon khong ton tai, vui long nhap lai.\n");
                }
            } while (choice != 9);

            return 0;
        }