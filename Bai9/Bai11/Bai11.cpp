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
    if (viTri < 0 || viTri >= n)
    {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }

    for (int i = viTri; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    a = (int*)realloc(a, n * sizeof(int));
}

void themPhanTu(int*& a, int& n, int x, int viTri)
{
    if (viTri < 0 || viTri > n)
    {
        printf("Vi tri them khong hop le.\n");
        return;
    }

    n++;
    a = (int*)realloc(a, n * sizeof(int));
    for (int i = n - 1; i > viTri; i--)
    {
        a[i] = a[i - 1];
    }
    a[viTri] = x;
}

void chuyenChanLe(int* a, int n)
{
    int* temp = (int*)malloc(n * sizeof(int));
    int even_count = 0;
    int odd_count = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            temp[even_count++] = a[i];
        }
        else
        {
            temp[odd_count--] = a[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    free(temp);
}

void xuatSoCucTieu(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = a[i];
        bool is_valley = true;

        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] < current)
            {
                is_valley = false;
                break;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < current)
            {
                is_valley = false;
                break;
            }
        }

        if (is_valley)
        {
            printf("%d ", current);
        }
    }
    printf("\n");
}

bool kiemTraChanLeXenKe(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0))
        {
            return true;
        }
    }
    return false;
}

void giaiPhong(int*& a)
{
    free(a);
    a = NULL;
}

void menu(int* a, int n)
{
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
        printf("5. Xoa phan tu tai vi tri k\n");
        printf("6. Them phan tu x vao vi tri k\n");
        printf("7. Chuyen so chan len dau, so le xuong cuoi mang\n");
        printf("8. Xuat cac so cuc tieu trong mang\n");
        printf("9. Kiem tra mang co chua chan le xen ke khong\n");
        printf("10. Thoat chuong trinh\n");
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
            {
                int k;
                printf("Nhap vi tri k can xoa: ");
                scanf_s("%d", &k);
                xoaPhanTu(a, n, k);
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 6:
            if (n > 0)
            {
                int x, k;
                printf("Nhap gia tri phan tu can them: ");
                scanf_s("%d", &x);
                printf("Nhap vi tri k can them: ");
                scanf_s("%d", &k);
                themPhanTu(a, n, x, k);
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 7:
            if (n > 0)
                chuyenChanLe(a, n);
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 8:
            if (n > 0)
            {
                printf("Cac so cuc tieu trong mang: ");
                xuatSoCucTieu(a, n);
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 9:
            if (n > 0)
            {
                if (kiemTraChanLeXenKe(a, n))
                    printf("Mang chua chan le xen ke.\n");
                else
                    printf("Mang khong chua chan le xen ke.\n");
            }
            else
                printf("Mang chua duoc nhap.\n");
            break;
        case 10:
            exit = true;
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    }

    giaiPhong(a);
}

int main()
{
    int* a = NULL;
    int n = 0;

    menu(a, n);

    return 0;
}
