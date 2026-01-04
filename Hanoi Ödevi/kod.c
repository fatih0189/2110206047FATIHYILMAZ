#include <stdio.h>

void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, to, aux);     // 1. adım
    printf("Disk %d: %c -> %c\n", n, from, to); // 2. adım
    hanoi(n - 1, aux, from, to);     // 3. adım
}

int main() {
    int n;
    printf("Disk sayisini gir: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');
    return 0;
}
