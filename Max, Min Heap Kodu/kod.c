#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

/* ---------- YARDIMCI ---------- */
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

/* ================= MAX HEAP ================= */

// Max Heap'e ekleme
void insertMax(int value) {
    int i = size;
    heap[size++] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Max Heap'ten silme (root)
void deleteMax() {
    if (size == 0) return;

    heap[0] = heap[--size];
    int i = 0;

    while (1) {
        int l = 2*i + 1, r = 2*i + 2, largest = i;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
}

/* ================= MIN HEAP ================= */

// Min Heap'e ekleme
void insertMin(int value) {
    int i = size;
    heap[size++] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Min Heap'ten silme (root)
void deleteMin() {
    if (size == 0) return;

    heap[0] = heap[--size];
    int i = 0;

    while (1) {
        int l = 2*i + 1, r = 2*i + 2, smallest = i;
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

/* ---------- YAZDIR ---------- */
void printHeap() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

/* ================= MAIN ================= */
int main() {

    /* -------- MAX HEAP TEST -------- */
    insertMax(10);
    insertMax(30);
    insertMax(20);
    insertMax(5);

    printf("Max Heap: ");
    printHeap();

    deleteMax();
    printf("Max Heap (silme sonrasi): ");
    printHeap();

    /* Heap sifirla */
    size = 0;

    /* -------- MIN HEAP TEST -------- */
    insertMin(10);
    insertMin(30);
    insertMin(20);
    insertMin(5);

    printf("Min Heap: ");
    printHeap();

    deleteMin();
    printf("Min Heap (silme sonrasi): ");
    printHeap();

    return 0;
}
