#include <stdio.h>

// Hàm nhập mảng từ bàn phím
void nhapMang(int a[][100], int n, int m) {
    printf("Nhap gia tri cac phan tu cua mang:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Hàm in mảng ra màn hình
void inMang(int a[][100], int n, int m) {
    printf("Gia tri cac phan tu trong mang:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm đếm số lượng phần tử chia hết cho 2 và 3 trong mảng
int demPhanTuChiaHet2Va3(int a[][100], int n, int m) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 == 0 && a[i][j] % 3 == 0) {
                dem++;
            }
        }
    }
    return dem;
}

// Hàm in phần tử và tổng các phần tử nằm trên đường biên, đường chéo chính và đường chéo phụ
void inPhanTuTrenDuongBienVaCheo(int a[][100], int n, int m) {
    int tongDuongBien = 0;
    int tongDuongCheoChinh = 0;
    int tongDuongCheoPhu = 0;

    printf("Cac phan tu tren duong bien:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%4d", a[i][j]);
                tongDuongBien += a[i][j];
            } else {
                printf("    ");
            }

            if (i == j) {
                tongDuongCheoChinh += a[i][j];
            }

            if (i + j == n - 1) {
                tongDuongCheoPhu += a[i][j];
            }
        }
        printf("\n");
    }

    printf("Tong cac phan tu tren duong bien: %d\n", tongDuongBien);
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongDuongCheoChinh);
    printf("Tong cac phan tu tren duong cheo phu: %d\n", tongDuongCheoPhu);
}

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Hàm in các số nguyên tố trong mảng
void inSoNguyenTo(int a[][100], int n, int m) {
    printf("Cac so nguyen to trong mang:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (laSoNguyenTo(a[i][j])) {
                printf("%4d", a[i][j]);
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

// Hàm sắp xếp các phần tử tăng dần theo cột của mảng
void sapXepTangDanTheoCot(int a[][100], int n, int m) {
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n - 1; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (a[i][j] > a[k][j]) {
                    // Hoán đổi giá trị
                    int temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
            }
        }
    }
}

// Hàm nổi bọt sắp xếp các phần tử trên đường chéo chính giảm dần
void sapXepNoiBotCheoChinhGiamDan(int a[][100], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j][j] < a[j + 1][j + 1]) {
                // Hoán đổi giá trị
                int temp = a[j][j];
                a[j][j] = a[j + 1][j + 1];
                a[j + 1][j + 1] = temp;
            }
        }
    }
}

// Hàm chèn mảng 1 chiều vào mảng 2 chiều tại dòng được chỉ định
void chenMang1ChieuVaoMang2Chieu(int a1[], int m, int a2[][100], int dongChen, int n, int m2) {
    // Di chuyển các dòng phía sau xuống
    for (int i = n - 1; i >= dongChen; --i) {
        for (int j = 0; j < m2; ++j) {
            a2[i + 1][j] = a2[i][j];
        }
    }

    // Chèn mảng 1 chiều vào dòng được chỉ định
    for (int j = 0; j < m2; ++j) {
        a2[dongChen][j] = a1[j];
    }
}

int main() {
    int n, m;
    int a[100][100];

    printf("Nhap so dong n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);

    int choice;

    do {
        printf("\n************************MENU**************************\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu trong mang theo ma tran\n");
        printf("3. Tinh so luong cac phan tu chia het cho 2 va 3 trong mang\n");
        printf("4. In cac phan tu va tong cac phan tu tren duong bien, duong cheo chinh va duong cheo phu\n");
        printf("5. Sap xep cac phan tu tang dan theo cot cua mang va in ra\n");
        printf("6. In ra cac phan tu la so nguyen to trong mang\n");
        printf("7. Sap xep cac phan tu tren duong cheo chinh giam dan bang thuat toan noi bot\n");
        printf("8. Nhap gia tri mot mang 1 chieu va chi so dong muon chen vao mang 2 chieu, thuc hien chen vao mang va in ra\n");
        printf("9. Thoat\n");
        printf("Chon chuc nang (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(a, n, m);
                break;
            case 2:
                inMang(a, n, m);
                break;
            case 3:
                printf("So luong phan tu chia het cho 2 va 3: %d\n", demPhanTuChiaHet2Va3(a, n, m));
                break;
            case 4:
                inPhanTuTrenDuongBienVaCheo(a, n, m);
                break;
            case 5:
                sapXepTangDanTheoCot(a, n, m);
                inMang(a, n, m);
                break;
            case 6:
                inSoNguyenTo(a, n, m);
                break;
            case 7:
                sapXepNoiBotCheoChinhGiamDan(a, n);
                inMang(a, n, m);
                break;
            case 8:
                printf("Nhap gia tri mang 1 chieu:\n");
                int a1[100];
                for (int i = 0; i < m; ++i) {
                    printf("Nhap a1[%d]: ", i);
                    scanf("%d", &a1[i]);
                }

                int dongChen;
                printf("Nhap dong muon chen vao mang 2 chieu: ");
                scanf("%d", &dongChen);

                chenMang1ChieuVaoMang2Chieu(a1, m, a, dongChen, n, m);
                inMang(a, n + 1, m);
                break;
            case 9:
                printf("Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }

    } while (choice != 9);

    return 0;
}
