#include <stdio.h>
#include <stdlib.h>

// Node yapisi
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

/* ----------- ARAYA EKLEME (Belirli bir degerden sonra) ----------- */
void insertAfter(int after, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // Liste bos ise
    if (head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Araya ekleme yapilacak eleman bulunamadi!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

/* ----------- SILME (Degere gore) ----------- */
void deleteNode(int value) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    struct Node* temp = head;

    // Silinecek node'u bul
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Silinecek eleman bulunamadi!\n");
        return;
    }

    // Head siliniyorsa
    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}

/* ----------- DOLASIM (Ileri) ----------- */
void displayForward() {
    struct Node* temp = head;
    printf("Ileri dolasim: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ----------- DOLASIM (Geri) ----------- */
void displayBackward() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Liste bos!\n");
        return;
    }

    // En sona git
    while (temp->next != NULL)
        temp = temp->next;

    printf("Geri dolasim: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* ----------- MAIN ----------- */
int main() {

    // Ilk node'lar
    insertAfter(0, 10);   // Liste bosken ekleme
    insertAfter(10, 20);
    insertAfter(20, 30);
    insertAfter(30, 40);

    displayForward();
    displayBackward();

    printf("\n20'den sonra 25 ekleniyor...\n");
    insertAfter(20, 25);
    displayForward();

    printf("\n30 siliniyor...\n");
    deleteNode(30);
    displayForward();
    displayBackward();

    return 0;
}
