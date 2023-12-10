#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a, b, choice;
    do {
        printf("Nhap vao 2 so nguyen: ");
        scanf("%d %d", &a, &b);
        printf("CACULATOR\n");
        printf("1. Tong 2 so\n");
        printf("2. Hieu 2 so\n");
        printf("3. Tich 2 so\n");
        printf("4. Thuong 2 so\n");
        printf("5. So du trong phep chia 2 so\n");
        printf("6. Uoc chung lon nhat\n");
        printf("7. Boi chung nho nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Tong: %d\n", a + b);
                break;
            case 2:
                printf("Hieu: %d\n", a - b);
                break;
            case 3:
                printf("Tich: %d\n", a * b);
                break;
            case 4:
                if(b != 0) {
                    printf("Thuong: %d\n", a / b);
                } else {
                    printf("Khong the chia cho 0!\n");
                }
                break;
            case 5:
                printf("So du: %d\n", a % b);
                break;
            case 6:
                printf("Uoc chung lon nhat: %d\n", gcd(a, b));
                break;
            case 7:
                printf("Boi chung nho nhat: %d\n", lcm(a, b));
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 8);

    return 0;
}
