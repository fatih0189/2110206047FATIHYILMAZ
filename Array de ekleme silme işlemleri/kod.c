#include <stdio.h>

#define MAX 20

int main() {
    int arr[MAX], n, i;
    int pos, value, choice;

    // Array oluşturma
    printf("Eleman sayisini gir: ");
    scanf("%d", &n);

    printf("Array elemanlarini gir:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n1 - Ekleme\n2 - Silme\nSecim yap: ");
    scanf("%d", &choice);

    // EKLEME
    if (choice == 1) {
        printf("Eklenecek deger: ");
        scanf("%d", &value);

        printf("Pozisyon (0-%d): ", n);
        scanf("%d", &pos);

        if (pos < 0 || pos > n || n >= MAX) {
            printf("Gecersiz pozisyon!\n");
            return 0;
        }

        for (i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = value;
        n++;

        printf("Ekleme sonrasi array:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    // SILME
    else if (choice == 2) {
        printf("Silinecek pozisyon (0-%d): ", n - 1);
        scanf("%d", &pos);

        if (pos < 0 || pos >= n) {
            printf("Gecersiz pozisyon!\n");
            return 0;
        }

        for (i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Silme sonrasi array:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
    else {
        printf("Gecersiz secim!\n");
    }

    return 0;
}
