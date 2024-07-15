#include <stdio.h>

void print_menu() {
    printf("\nChon mot chuc nang:");
    printf("\n1. Tinh tong");
    printf("\n2. Tinh hieu");
    printf("\n3. Tinh tich");
    printf("\n4. Tinh thuong");
    printf("\n5. Thoat");
    printf("\nLua chon cua ban: ");
}

int main() {
    float a = 7.7, b = 4.7;
    float* pa = &a;
    float* pb = &b;

    float sum, diff, prod, quot;
    float* psum = &sum, * pdiff = &diff, * pprod = &prod, * pquot = &quot;
    int choice;

    while (1) {
        print_menu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            *psum = *pa + *pb;
            printf("\nTong cua a va b: %f, dia chi: %p", *psum, (void*)psum);
            break;
        case 2:
            *pdiff = *pa - *pb;
            printf("\nHieu cua a va b: %f, dia chi: %p", *pdiff, (void*)pdiff);
            break;
        case 3:
            *pprod = *pa * *pb;
            printf("\nTich cua a va b: %f, dia chi: %p", *pprod, (void*)pprod);
            break;
        case 4:
            *pquot = *pa / *pb;
            printf("\nThuong cua a va b: %f, dia chi: %p", *pquot, (void*)pquot);
            break;
        case 5:
            printf("\nThoat chuong trinh.");
            return 0;
        default:
            printf("\nLua chon khong hop le. Vui long chon lai.");
        }

        printf("\nDia chi cua a: %p", (void*)pa);
        printf("\nDia chi cua b: %p", (void*)pb);
        printf("\nSo a duoc nhap la: %f", a);
        printf("\nSo b duoc nhap la: %f", b);

    }
    return 0;
}
