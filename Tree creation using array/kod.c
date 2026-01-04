#include <stdio.h>

#define MAX 20

char tree[MAX];
int n;

int main() {
    int index;

    // Tree oluşturma
    printf("Eleman sayisini gir: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i);
        scanf(" %c", &tree[i]);
    }

    // Tree yazdırma (Level Order)
    printf("\nTree (Array - Level Order): ");
    for (int i = 0; i < n; i++) {
        printf("%c ", tree[i]);
    }
    printf("\n");

    // Çocukları gösterme
    printf("\nHangi node icin cocuklari gosterelim? (index): ");
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Gecersiz index!\n");
        return 0;
    }

    if (2 * index + 1 < n)
        printf("Sol cocuk: %c\n", tree[2 * index + 1]);
    else
        printf("Sol cocuk yok\n");

    if (2 * index + 2 < n)
        printf("Sag cocuk: %c\n", tree[2 * index + 2]);
    else
        printf("Sag cocuk yok\n");

    return 0;
}
