#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapMang(int*& a, int& n)
{
    printf("Nhap so luong phan tu cua mang: ");
    scanf_s("%d", &n);

    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
}

void xuatMang(int* a, int n)
{
    printf("Mang so nguyen:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void timLonNhat(int* a, int n)
{
    if (n == 0) return;
    int max = a[0];
    int* max_ptr = a;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            max_ptr = &a[i];
        }
    }
    printf("Phan tu lon nhat: %d, dia chi: %p\n", max, (void*)max_ptr);
}

void timChanLe(int* a, int n)
{
    int* max_even_ptr = NULL;
    int* min_odd_ptr = NULL;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (max_even_ptr == NULL || a[i] > *max_even_ptr)
            {
                max_even_ptr = &a[i];
            }
        }
        else
        {
            if (min_odd_ptr == NULL || a[i] < *min_odd_ptr)
            {
                min_odd_ptr = &a[i];
            }
        }
    }

    if (max_even_ptr != NULL)
        printf("Phan tu chan lon nhat: %d, dia chi: %p\n", *max_even_ptr, (void*)max_even_ptr);
    else
        printf("Khong co phan tu chan trong mang.\n");

    if (min_odd_ptr != NULL)
        printf("Phan tu le nho nhat: %d, dia chi: %p\n", *min_odd_ptr, (void*)min_odd_ptr);
    else
        printf("Khong co phan tu le trong mang.\n");
}

void xoaPhanTu(int*& a, int& n, int viTri)
{
    for (int i = viTri; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    a = (int*)realloc(a, n * sizeof(int));
}

void xoaPhanTuCoGiaTri0(int*& a, int& n)
{
    for (int i = 0; i < n; )
    {
        if (a[i] == 0)
        {
            xoaPhanTu(a, n, i);
        }
        else
        {
            i++;
        }
    }
}

void themPhanTu(int*& a, int& n, int x)
{
    n++;
    a = (int*)realloc(a, n * sizeof(int));
    for (int i = n - 1; i > 1; i--)
    {
        a[i] = a[i - 1];
    }
    a[1] = x;
}

int kiemTraSoChinhPhuong(int x)
{
    int sqrt_x = (int)sqrt(x);
    return (sqrt_x * sqrt_x == x);
}

int tongSoChinhPhuong(int* a, int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (kiemTraSoChinhPhuong(a[i]))
            tong += a[i];
    }
    return tong;
}

void xuatSoCucDai(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = a[i];
        bool is_peak = true;

        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > current)
            {
                is_peak = false;
                break;
            }
        }

        if (is_peak)
        {
            printf("%d ", current);
        }
    }
    printf("\n");
}

void giaiPhong(int*& a)
{
    free(a);
    a = NULL;
}

int main()
{
    int* a = NULL;
    int n = 0;
    int choice;
    bool exit = false;

    while (!exit)
    {
        printf("\n---------------------------------\n");
        printf("Menu:\n");
        printf("1. Nhap mang\n");
        printf("2. Xuat mang\n");
        printf("3. Tim phan tu lon nhat\n");
        printf("4. Tim phan tu chan lon nhat va phan tu le nho nhat\n");
        printf("5. Xoa phan tu co gia tri 0\n");
        printf("6. Them phan tu vao sau phan tu dau tien\n");
        printf("7. Tinh tong cac so chinh phuong\n");
        printf("8. Xuat cac so cuc dai trong mang\n");
        printf("9. Thoat chuong trinh\n");
        printf("---------------------------------\n");

        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1:
            nhapMang(a, n);
            break;
        case 2:
            if (n > 0)
                xuatMang(a, n);
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 3:
            if (n > 0)
                timLonNhat(a, n);
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 4:
            if (n > 0)
                timChanLe(a, n);
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 5:
            if (n > 0)
                xoaPhanTuCoGiaTri0(a, n);
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 6:
            if (n > 0)
            {
                int x;
                printf("Nhap gia tri phan tu can them: ");
                scanf_s("%d", &x);
                themPhanTu(a, n, x);
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 7:
            if (n > 0)
            {
                int tong_chinh_phuong = tongSoChinhPhuong(a, n);
                printf("Tong cac so chinh phuong trong mang: %d\n", tong_chinh_phuong);
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 8:
            if (n > 0)
            {
                printf("Cac so cuc dai trong mang: ");
                xuatSoCucDai(a, n);
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 9:
            exit = true;
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    }

    giaiPhong(a);
    return 0;
}
