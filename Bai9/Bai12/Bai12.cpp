#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct PhanSo {
    int tu;
    int mau;

    PhanSo() = default;
};


void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf_s("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf_s("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}


void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tu, ps.mau);
}


void nhapMangPhanSo(PhanSo* mang, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&mang[i]);
    }
}

void xuatMangPhanSo(PhanSo* mang, int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(mang[i]);
    }
}

void xuatPhanSoMauLonHonTu(PhanSo* mang, int n) {
    printf("Cac phan so co mau > tu:\n");
    for (int i = 0; i < n; i++) {
        if (mang[i].mau > mang[i].tu) {
            xuatPhanSo(mang[i]);
        }
    }
}

int demPhanSoChan(PhanSo* mang, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (mang[i].tu % 2 == 0 && mang[i].mau % 2 == 0) {
            count++;
        }
    }
    return count;
}

int UCLN(int a, int b) {
    if (b == 0) {
        return a;
    }
    return UCLN(b, a % b);
}

PhanSo rutGonPhanSo(PhanSo ps) {
    int ucln = UCLN(abs(ps.tu), abs(ps.mau));
    ps.tu /= ucln;
    ps.mau /= ucln;
    return ps;
}

PhanSo tinhTich(PhanSo* mang, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu *= mang[i].tu;
        tich.mau *= mang[i].mau;
    }
    return rutGonPhanSo(tich);
}

PhanSo timPhanSoLonNhat(PhanSo* mang, int n) {
    PhanSo max = mang[0];
    for (int i = 1; i < n; i++) {
        if ((float)mang[i].tu / mang[i].mau > (float)max.tu / max.mau) {
            max = mang[i];
        }
    }
    return max;
}

PhanSo timPhanSoNhoNhat(PhanSo* mang, int n) {
    PhanSo min = mang[0];
    for (int i = 1; i < n; i++) {
        if ((float)mang[i].tu / mang[i].mau < (float)min.tu / min.mau) {
            min = mang[i];
        }
    }
    return min;
}

void xoaPhanTuTaiViTri(PhanSo* mang, int& n, int k) {
    if (k < 0 || k >= n) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }
    for (int i = k; i < n - 1; i++) {
        mang[i] = mang[i + 1];
    }
    n--;
}

void themPhanTuTaiViTri(PhanSo* mang, int& n, PhanSo x, int k) {
    if (k < 0 || k > n) {
        printf("Vi tri them khong hop le.\n");
        return;
    }
    for (int i = n; i > k; i--) {
        mang[i] = mang[i - 1];
    }
    mang[k] = x;
    n++;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf_s("%d", &n);

    PhanSo* mang = (PhanSo*)malloc(n * sizeof(PhanSo));

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Nhap mang phan so\n");
        printf("2. Xuat mang phan so\n");
        printf("3. Xuat phan so co mau > tu\n");
        printf("4. Dem so phan so co mau va tu chan\n");
        printf("5. Rut gon cac phan so trong mang\n");
        printf("6. Tinh tich cac phan so\n");
        printf("7. Tim phan so lon nhat\n");
        printf("8. Tim phan so nho nhat\n");
        printf("9. Xoa phan tu tai vi tri k\n");
        printf("10. Them phan tu x tai vi tri k\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            nhapMangPhanSo(mang, n);
            break;
        case 2:
            printf("Mang phan so vua nhap:\n");
            xuatMangPhanSo(mang, n);
            break;
        case 3:
            xuatPhanSoMauLonHonTu(mang, n);
            break;
        case 4: {
            int soPhanSoChan = demPhanSoChan(mang, n);
            printf("So phan so co mau va tu chan: %d\n", soPhanSoChan);
            break;
        }
        case 5:
            for (int i = 0; i < n; i++) {
                mang[i] = rutGonPhanSo(mang[i]);
            }
            printf("Mang phan so sau khi rut gon:\n");
            xuatMangPhanSo(mang, n);
            break;
        case 6: {
            PhanSo tich = tinhTich(mang, n);
            printf("Tich cac phan so: ");
            xuatPhanSo(tich);
            break;
        }
        case 7: {
            PhanSo max = timPhanSoLonNhat(mang, n);
            printf("Phan so lon nhat: ");
            xuatPhanSo(max);
            break;
        }
        case 8: {
            PhanSo min = timPhanSoNhoNhat(mang, n);
            printf("Phan so nho nhat: ");
            xuatPhanSo(min);
            break;
        }
        case 9: {
            int k;
            printf("Nhap vi tri can xoa: ");
            scanf_s("%d", &k);
            xoaPhanTuTaiViTri(mang, n, k);
            printf("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
            xuatMangPhanSo(mang, n);
            break;
        }
        case 10: {
            int k;
            PhanSo x;
            printf("Nhap phan so can them:\n");
            nhapPhanSo(&x);
            printf("Nhap vi tri can them: ");
            scanf_s("%d", &k);
            themPhanTuTaiViTri(mang, n, x, k);
            printf("Mang sau khi them phan tu tai vi tri %d:\n", k);
            xuatMangPhanSo(mang, n);
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 0);

    free(mang);
    return 0;
}
