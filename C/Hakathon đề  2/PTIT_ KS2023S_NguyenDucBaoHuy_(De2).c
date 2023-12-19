#include <stdio.h>
#include <stdlib.h>

// Function to check prime numbers (case 6)
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

// Function to perform selection sort on a one-dimensional array (case 5)
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

// Function to print a two-dimensional array
void printArray(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Function to sort columns of a two-dimensional array (case 5)
void sortColumns(int **a, int n, int m) {
    int *temp = (int *) malloc(n * sizeof(int));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
            temp[i] = a[i][j];
        selectionSort(temp, n);
        for (int i = 0; i < n; i++)
            a[i][j] = temp[i];
    }
    free(temp);
}

// Function to perform bubble sort on the main diagonal of a two-dimensional array (case 7)
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

// Function to insert a one-dimensional array into a specific row of a two-dimensional array (case 8)
void insertArrayIntoMatrix(int** a, int* b, int* n, int m, int k) {
    // Tạo một mảng mới với kích thước lớn hơn 1
    int** new_a = (int**)malloc((*n + 1) * sizeof(int*));
    for (int i = 0; i < *n + 1; i++) {
        new_a[i] = (int*)malloc(m * sizeof(int));
    }

    // Chèn các phần tử từ mảng cũ và mảng b vào mảng mới
    for (int i = 0; i < *n + 1; i++) {
        if (i < k) {
            new_a[i] = a[i];
        } else if (i == k) {
            new_a[i] = b;
        } else {
            new_a[i] = a[i - 1];
        }
    }
}



// Function to print elements on the boundary and main diagonals and calculate their sum (case 4)
void printAndSumBoundariesAndDiagonals(int **a, int n, int m) {
    int sum = 0;
    printf("Cac phan tu nam tren duong bien: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                printf("%d ", a[i][j]);
                sum += a[i][j];
            }
    printf("\nCac phan tu nam tren duong cheo chinh: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == j) {
                printf("%d ", a[i][j]);
                sum += a[i][j];
            }
    printf("\nCac phan tu nam tren duong cheo phu: ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + j == n - 1) {
                printf("%d ", a[i][j]);
                sum += a[i][j];
            }
    printf("\nTong cac phan tu nam tren duong bien, duong cheo chinh va duong cheo phu: %d\n", sum);
}

int main() {
    int n, m, *b, count,k;
    printf("Nhap so dong (n): ");
    scanf("%d", &n);
    printf("Nhap so cot (m): ");
    scanf("%d", &m);

    int **a = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = (int *) malloc(m * sizeof(int));

    int choice;
    do {
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. Tinh so luong cac phan tu chia het cho 2 va 3 trong mang\n");
        printf("4. In cac phan tu va tong cac phan tu nam tren duong bien, duong cheo chinh va duong cheo phu\n");
        printf("5. Su dung thuat toan sap xep lua chon sap xep cac phan tu tang dan theo cot cua mang\n");
        printf("6. In ra cac phan tu la so nguyen to trong mang\n");
        printf("7. Su dung thuat toan noi bot sap xep cac phan tu tren duong cheo chinh cua mang giam dan\n");
        printf("8. Nhap gia tri mot mang 1 chieu gom m phan tu va chi so dong muon chen vao mang, thuc hien chen vao mang 2 chieu\n");
        printf("9. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Nhập giá trị các phần tử của mảng
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) {
                        printf("Nhap a[%d][%d] = ", i, j);
                        scanf("%d", &a[i][j]);
                    }
                break;
            case 2:
                // In giá trị các phần tử trong mảng theo ma trận
                printArray(a, n, m);
                break;
            case 3:
                // Tính số lượng các phần tử chia hết cho 2 và 3 trong mảng
                count = 0;  // Initialize count here
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++)
                        if (a[i][j] % 2 == 0 && a[i][j] % 3 == 0)
                            count++;
                printf("So luong phan tu chia het cho 2 va 3 trong mang la: %d phan tu\n", count);
                break;
            case 4:
                printAndSumBoundariesAndDiagonals(a, n, m);
                break;
            case 5:
                // Sử dụng thuật toán sắp xếp lựa chọn sắp xếp các phần tử tăng dần theo cột của mảng
                sortColumns(a, n, m);
                printf("Mang sau khi sap xep cac phan tu tang dan theo cot:\n");
                printArray(a, n, m);
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
                printf("Mang truoc khi sap xep duong cheo chinh:\n");
                printArray(a, n, n);

                // Sắp xếp các phần tử trên đường chéo chính giảm dần
                bubbleSortMainDiagonal(a, n);
                printf("Mang sau khi sap xep duong cheo chinh giam dan:\n");
                printArray(a, n, n);
                break;
            case 8:
                // Nhập giá trị một mảng 1 chiều gồm m phần tử và chỉ số dòng muốn chèn vào mảng, thực hiện chèn vào mảng 2 chiều
                printf("Nhap chi so dong muon chen: ");
                scanf("%d", &k);
                insertArrayIntoMatrix(a, b, &n, m, k);
                printf("Mang sau khi chen:\n");
                printArray(a, n, m);
                break;
            case 9:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong ton tai, vui long nhap lai.\n");
        }
    } while (choice != 9);

    // Free the memory allocated for the two-dimensional array
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}