#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
} ;

struct NguoiLaoDong {
    char hoTen[100];
    Date ngaySinh;
    char gioiTinh[10];
} ;

int tinhTuoi(Date ngaySinh, int namHienTai) {
    return namHienTai - ngaySinh.year;
}

int kiemTraNgoaiLe(NguoiLaoDong nguoi, int namHienTai) {
    int tuoi = tinhTuoi(nguoi.ngaySinh, namHienTai);
    if (strcmp(nguoi.gioiTinh, "nam") == 0) {
        if (tuoi < 15 || tuoi > 62) {
            return 101;
        }
    }
    else if (strcmp(nguoi.gioiTinh, "nu") == 0) {
        if (tuoi < 15 || tuoi > 60) {
            return 101;
        }
    }
    else {
        return -1;
    }
    return 0;
}

void xacDinhThoiGianNghiHuu(NguoiLaoDong nguoi, int* tuoiNghiHuu, int* thangNghiHuu) {
    int namSinh = nguoi.ngaySinh.year;
    if (strcmp(nguoi.gioiTinh, "nam") == 0) {
        if (namSinh <= 1961) {
            *tuoiNghiHuu = 60;
            *thangNghiHuu = 3;
        }
        else if (namSinh == 1962) {
            *tuoiNghiHuu = 60;
            *thangNghiHuu = 6;
        }
        else if (namSinh == 1963) {
            *tuoiNghiHuu = 60;
            *thangNghiHuu = 9;
        }
        else if (namSinh == 1964) {
            *tuoiNghiHuu = 61;
            *thangNghiHuu = 0;
        }
        else if (namSinh == 1965) {
            *tuoiNghiHuu = 61;
            *thangNghiHuu = 3;
        }
        else if (namSinh == 1966) {
            *tuoiNghiHuu = 61;
            *thangNghiHuu = 6;
        }
        else if (namSinh == 1967) {
            *tuoiNghiHuu = 61;
            *thangNghiHuu = 9;
        }
        else {
            *tuoiNghiHuu = 62;
            *thangNghiHuu = 0;
        }
    }
    else { // nu
        if (namSinh <= 1966) {
            *tuoiNghiHuu = 55;
            *thangNghiHuu = 4;
        }
        else if (namSinh == 1967) {
            *tuoiNghiHuu = 56;
            *thangNghiHuu = 0;
        }
        else if (namSinh == 1968) {
            *tuoiNghiHuu = 56;
            *thangNghiHuu = 4;
        }
        else if (namSinh == 1969) {
            *tuoiNghiHuu = 56;
            *thangNghiHuu = 8;
        }
        else if (namSinh == 1970) {
            *tuoiNghiHuu = 57;
            *thangNghiHuu = 0;
        }
        else if (namSinh >= 1971 && namSinh <= 1975) {
            *tuoiNghiHuu = 58 + (namSinh - 1971);
            *thangNghiHuu = 4;
        }
        else {
            *tuoiNghiHuu = 60;
            *thangNghiHuu = 0;
        }
    }
}

void tinhThoiGianNghiHuu(NguoiLaoDong nguoi) {
    int tuoiNghiHuu, thangNghiHuu;
    xacDinhThoiGianNghiHuu(nguoi, &tuoiNghiHuu, &thangNghiHuu);

    int namNghiHuu = nguoi.ngaySinh.year + tuoiNghiHuu;
    int thangNghiHuuThuc = nguoi.ngaySinh.month + thangNghiHuu;

    if (thangNghiHuuThuc > 12) {
        namNghiHuu++;
        thangNghiHuuThuc -= 12;
    }

    printf("%s se nghi huu vao thang %d nam %d\n", nguoi.hoTen, thangNghiHuuThuc, namNghiHuu);
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

    tinhThoiGianNghiHuu(nguoi);
    return 0;
}