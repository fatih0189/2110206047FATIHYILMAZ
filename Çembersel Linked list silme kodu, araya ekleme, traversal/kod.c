#include <stdio.h>
#include <stdlib.h>

// Node yapisi
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/* ----------- EKLEME (Sona ekleme) ----------- */
void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // Liste bos ise
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } 
    else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

/* ----------- SILME (Degere gore) ----------- */
void deleteNode(int value) {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    struct Node *curr = head, *prev = NULL;

    // Tek elemanli liste
    if (head->data == value && head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    // Head siliniyorsa
    if (head->data == value) {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = head->next;
        head = head->next;
        free(curr);
        return;
    }

    // Ortadan veya sondan silme
    prev = head;
    curr = head->next;
    while (curr != head) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Eleman bulunamadi!\n");
}

/* ----------- DOLASIM (Traversal) ----------- */
void display() {
    if (head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* ----------- MAIN ----------- */
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();

    printf("20 siliniyor...\n");
    deleteNode(20);
    display();

    printf("10 siliniyor...\n");
    deleteNode(10);
    display();

    return 0;
}
