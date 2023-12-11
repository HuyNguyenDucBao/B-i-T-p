#include <stdio.h>

int main() {
    int soPhut, cuocPhi;
    const int phiThueBao = 25000;
    printf("Nhap so phut su dung: ");
    scanf("%d", &soPhut);

    if(soPhut <= 50) {
        cuocPhi = phiThueBao + soPhut * 600;
    } else if(soPhut <= 200) {
        cuocPhi = phiThueBao + 50 * 600 + (soPhut - 50) * 400;
    } else if(soPhut <= 400) {
        cuocPhi = phiThueBao + 50 * 600 + 150 * 400 + (soPhut - 200) * 200;
    } else {
        cuocPhi = phiThueBao + 50 * 600 + 150 * 400 + 200 * 200 + (soPhut - 400) * 100;
    }

    printf("Cuoc phi dien thoai ban la: %d VND\n", cuocPhi);

    return 0;
}