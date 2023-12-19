#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Hàm nhập mảng
void nhapMang(int a[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

// Hàm in mảng
void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// Hàm thêm phần tử
void themPhanTu(int a[], int *n, int pos, int val) {
    for (int i = *n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = val;
    (*n)++;
}

// Hàm sửa phần tử
void suaPhanTu(int a[], int pos, int val) {
    a[pos] = val;
}

// Hàm xóa phần tử
void xoaPhanTu(int a[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

// Hàm sắp xếp giảm dần
void sapXepGiam(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp tăng dần
void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

// Hàm tìm kiếm tuyến tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

// Hàm tìm kiếm nhị phân
int timKiemNhiPhan(int a[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] > x) {
            return timKiemNhiPhan(a, left, mid - 1, x);
        }
        return timKiemNhiPhan(a, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int a[MAX];
    int n = 0;
    int choice, pos, val, x;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Giam dan\n");
        printf("8. Tang dan\n");
        printf("9. Tim kiem phan tu nhap vao\n");
        printf("10. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(a, &n);
                break;
            case 2:
                inMang(a, n);
                break;
            case 3:
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &val);
                themPhanTu(a, &n, pos, val);
                break;
            case 4:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &val);
                suaPhanTu(a, pos, val);
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                xoaPhanTu(a, &n, pos);
                break;
            case 6:
                printf("1. Giam dan\n");
                printf("2. Tang dan\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    sapXepGiam(a, n);
                } else if (choice == 2) {
                    sapXepTang(a, n);
                } else {
                    printf("Lua chon khong hop le. Vui long nhap lai!\n");
                }
                break;
            case 7:
                sapXepGiam(a, n);
                break;
            case 8:
                sapXepTang(a, n);
                break;
            case 9:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &x);
                if (a[0] > a[1]) {
                    int index = timKiemTuyenTinh(a, n, x);
                    if (index != -1) {
                        printf("Tim thay %d tai vi tri %d\n", x, index);
                    } else {
                        printf("Khong tim thay %d trong mang\n", x);
                    }
                } else {
                    int index = timKiemNhiPhan(a, 0, n - 1, x);
                    if (index != -1) {
                        printf("Tim thay %d tai vi tri %d\n", x, index);
                    } else {
                        printf("Khong tim thay %d trong mang\n", x);
                    }
                }
                break;
            case 10:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai!\n");
                break;
        }
    } while (choice != 10);

    return 0;
}
