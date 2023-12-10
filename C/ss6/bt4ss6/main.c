#include <stdio.h>

int main() {
    int n, choice;
    do {
        printf("Nhap vao mot so nguyen n: ");
        scanf("%d", &n);
        printf("\nPRACTICE\n");
        printf("1. In day so chia het cho 2 va giam dan (n >= so >= 2)\n");
        printf("2. In cac so nho hon n va tinh tong\n");
        printf("3. In ra cac uoc so chan cua n\n");
        printf("4. In ra cac uoc so le va so luong cac uoc le cua n\n");
        printf("5. In ra uoc so le lon nhat cua n\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Day so chia het cho 2 va giam dan: ");
                for (int i = n; i >= 2; i--) {
                    if (i % 2 == 0) {
                        printf("%d ", i);
                    }
                }
                printf("\n");
                break;
            }
            case 2: {
                int sum = 0;
                printf("Cac so nho hon n: ");
                for (int i = 1; i < n; i++) {
                    printf("%d ", i);
                    sum += i;
                }
                printf("\nTong cac so nho hon n: %d\n", sum);
                break;
            }
            case 3: {
                printf("Cac uoc so chan cua n: ");
                for (int i = 2; i <= n; i += 2) {
                    if (n % i == 0) {
                        printf("%d ", i);
                    }
                }
                printf("\n");
                break;
            }
            case 4: {
                int count = 0;
                printf("Cac uoc so le cua n: ");
                for (int i = 1; i <= n; i += 2) {
                    if (n % i == 0) {
                        printf("%d ", i);
                        count++;
                    }
                }
                printf("\nSo luong cac uoc le cua n: %d\n", count);
                break;
            }
            case 5: {
                int maxOddDivisor = -1;
                for (int i = 1; i <= n; i += 2) {
                    if (n % i == 0) {
                        maxOddDivisor = i;
                    }
                }
                if (maxOddDivisor != -1) {
                    printf("Uoc so le lon nhat cua n: %d\n", maxOddDivisor);
                } else {
                    printf("Khong co uoc so le nao cua n.\n");
                }
                break;
            }
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}
