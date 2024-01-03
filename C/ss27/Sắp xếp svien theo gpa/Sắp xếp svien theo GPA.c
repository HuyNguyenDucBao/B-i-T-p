#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ten[50];
    char lop[50];
    char ngay_sinh[50];
    float gpa;
} sinhVien;

int compare(const void *a, const void *b) {
    return ((sinhVien *)b)->gpa - ((sinhVien *)a)->gpa;
}

int main() {
    FILE *file = fopen("sinhvien.txt", "r");
    sinhVien students[100];
    int i = 0;

    while(fscanf(file, "%[^,],%[^,],%[^,],%f\n", students[i].ten, students[i].lop, students[i].ngay_sinh, &students[i].gpa) != EOF) {
        i++;
    }

    fclose(file);

    qsort(students, i, sizeof(sinhVien), compare);

    file = fopen("sinhvien_out.txt", "w");

    for(int j = 0; j < i; j++) {
        fprintf(file, "%s,%s,%s,%.2f\n", students[j].ten, students[j].lop, students[j].ngay_sinh, students[j].gpa);
    }

    fclose(file);

    return 0;
}
