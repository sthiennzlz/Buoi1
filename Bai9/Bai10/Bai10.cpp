#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 1000

void print_menu() {
    printf("\nChon mot chuc nang:");
    printf("\n1. Xuat gia tri tung ky tu cua chuoi");
    printf("\n2. Chuyen chuoi ve chu hoa");
    printf("\n3. Chuyen ky tu dau moi tu ve chu hoa");
    printf("\n4. Thoat");
    printf("\nLua chon cua ban: ");
}

void xuat_ky_tu(const char* st) {
    while (*st != '\0') {
        printf("%c ", *st);
        st++;
    }
    printf("\n");
}

void chuyen_ve_chu_hoa(char* st) {
    while (*st != '\0') {
        *st = toupper(*st);
        st++;
    }
}

void chuyen_ky_tu_dau_ve_chu_hoa(char* st) {
    int first = 1;
    while (*st != '\0') {
        if (first && isalpha(*st)) {
            *st = toupper(*st);
            first = 0;
        }
        if (*st == ' ') {
            first = 1;
        }
        st++;
    }
}

int main() {
    char st[MAX_LENGTH];
    int choice;

    printf("Nhap chuoi: ");
    fgets(st, MAX_LENGTH, stdin);
    st[strcspn(st, "\n")] = 0;
    while (1) {
        print_menu();
        scanf_s("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Gia tri tung ky tu cua chuoi: ");
            xuat_ky_tu(st);
            break;
        case 2:
            chuyen_ky_tu_dau_ve_chu_hoa(st);
            printf("Chuoi sau khi chuyen ky tu dau moi tu ve chu hoa: %s\n", st);
            break;
        case 3:
            chuyen_ve_chu_hoa(st);
            printf("Chuoi sau khi chuyen ve chu hoa: %s\n", st);
            break;
        case 4:
            printf("Thoat chuong trinh.\n");
            printf("Vui long nhan Enter de thoat ra khoi chuong trinh. Xin cam on !!!\n");
            return 0;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
