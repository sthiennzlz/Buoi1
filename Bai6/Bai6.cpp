#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char hoTen[100];
    Date ngaySinh;
    char gioiTinh[10];
} NguoiLaoDong;

int tinhTuoi(Date ngaySinh, int namHienTai) {
    return namHienTai - ngaySinh.year;
}

int kiemTraNgoaiLe(NguoiLaoDong nguoi, int namHienTai) {
    int tuoi = tinhTuoi(nguoi.ngaySinh, namHienTai);

    if (strcmp(nguoi.gioiTinh, "nam") == 0) {
        if (tuoi < 18 || tuoi > 62) {
            return 101;
        }
    }
    else if (strcmp(nguoi.gioiTinh, "nu") == 0) {
        if (tuoi < 18 || tuoi > 60) {
            return 101;
        }
    }
    else {
        return -1;
    }
    return 0;
}

void tinhThoiGianNghiHuu(NguoiLaoDong nguoi, int namHienTai) {
    int tuoi = tinhTuoi(nguoi.ngaySinh, namHienTai);
    int namNghiHuu = nguoi.ngaySinh.year;

    if (strcmp(nguoi.gioiTinh, "nam") == 0) {
        namNghiHuu += 62;
    }
    else if (strcmp(nguoi.gioiTinh, "nu") == 0) {
        namNghiHuu += 60;
    }

    printf("%s se nghi huu vao nam %d\n", nguoi.hoTen, namNghiHuu);
}

int main() {
    NguoiLaoDong nguoi;
    int namHienTai = 2024;
    int err;

    printf("Nhap ho ten: ");
    fgets(nguoi.hoTen, sizeof(nguoi.hoTen), stdin);
    nguoi.hoTen[strcspn(nguoi.hoTen, "\n")] = '\0';

    printf("Nhap ngay sinh (dd mm yyyy): ");
    if (scanf_s("%d %d %d", &nguoi.ngaySinh.day, &nguoi.ngaySinh.month, &nguoi.ngaySinh.year) != 3) {
        printf("Loi: Ngay sinh khong hop le.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Nhap gioi tinh (nam/nu): ");
    fgets(nguoi.gioiTinh, sizeof(nguoi.gioiTinh), stdin);
    nguoi.gioiTinh[strcspn(nguoi.gioiTinh, "\n")] = '\0';

    err = kiemTraNgoaiLe(nguoi, namHienTai);
    if (err == 101) {
        printf("Loi 101: Tuoi khong thuoc trong tuoi lao dong.\n");
        return 1;
    }
    else if (err == -1) {
        printf("Loi: Gioi tinh khong hop le.\n");
        return 1;
    }

    tinhThoiGianNghiHuu(nguoi, namHienTai);

    return 0;
}