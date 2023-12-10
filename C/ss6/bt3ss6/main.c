#include <stdio.h>

int main() {
    int a, b, c, choice;
    do {
        printf("Nhap vao 3 so nguyen: ");
        scanf("%d %d %d", &a, &b, &c);
        printf("\nCACULATOR\n");
        printf("1. Tong 3 so nguyen\n");
        printf("2. Trung binh cong cua 3 so nguyen\n");
        printf("3. So lon nhat, nho nhat trong 3 so\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Tong 3 so nguyen: %d\n", a + b + c);
                break;
            case 2:
                printf("Trung binh cong cua 3 so nguyen: %.2f\n", (a + b + c) / 3.0);
                break;
            case 3:
                printf("So lon nhat trong 3 so: %d\n", (a > b) ? (a > c ? a : c) : (b > c ? b : c));
                printf("So nho nhat trong 3 so: %d\n", (a < b) ? (a < c ? a : c) : (b < c ? b : c));
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 4);

    return 0;
}
