#include <stdio.h>

typedef struct {
    int stt;
    char hoVaTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
    char lop[10];
    char khoa[10];
} SinhVien;

int main() {
    char ten[15]
    SinhVien danhSach[] = {
        {1, "Nguyen Van A", 20, "0904488481", "anv@rikkei.academy", "1", "1"},
        {2, "Nguyen Van B", 21, "0904488482", "bnv@rikkei.academy", "1", "1"},
        // Add more students here
    };
    int soLuongSV = sizeof(danhSach) / sizeof(danhSach[0]);

    printf("DANH SACH SINH VIEN\n");
    printf("STT | Ho va ten       | Tuoi | So dien thoai | email              | Lop | Khoa\n");
    for (int i = 0; i < soLuongSV; i++) {
        printf("%-4d| %-15s | %-4d | %-13s | %-18s | %-3s | %-4s\n",
               danhSach[i].stt,
               danhSach[i].hoVaTen,
               danhSach[i].tuoi,
               danhSach[i].soDienThoai,
               danhSach[i].email,
               danhSach[i].lop,
               danhSach[i].khoa);
    }
    return 0;
}
