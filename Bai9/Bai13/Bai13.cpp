#include <stdio.h>
#include <stdlib.h>

void tinhVaXuatKetQua(int* a, int n, int* b, int m) {
    if (m == 0) {
        printf("Loi: Mau so khong the la 0.\n");
        return;
    }

    int minLen = (n < m) ? n : m; 

    printf("Ket qua cac phep chia:\n");
    for (int i = 0; i < minLen; i++) {
        if (b[i] == 0) {
            printf("Phep chia %d / %d: Loi chia cho 0\n", a[i], b[i]);
        }
        else {
            float ketQua = (float)a[i] / b[i];
            printf("Phep chia %d / %d: %.2f\n", a[i], b[i], ketQua);
        }
    }
}

int main() {
    int n, m;

    printf("Nhap so luong phan tu cua mang a: ");
    scanf_s("%d", &n);

    printf("Nhap so luong phan tu cua mang b: ");
    scanf_s("%d", &m);

    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(m * sizeof(int));

    printf("Nhap cac phan tu cua mang a:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }

    printf("Nhap cac phan tu cua mang b:\n");
    for (int i = 0; i < m; i++) {
        printf("b[%d] = ", i);
        scanf_s("%d", &b[i]);
    }

    tinhVaXuatKetQua(a, n, b, m);

    free(a);
    free(b);

    return 0;
}
