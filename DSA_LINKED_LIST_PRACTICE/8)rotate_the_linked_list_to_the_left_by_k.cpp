/*Given a singly linked list and an integer k, rotate the linked list to the left by k
places.
Input Output
10->20->30->40->50, k = 4 50->10->20->30->40*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("\n");
}


void rotateLeft(struct Node** head, int k) {
    if (*head == NULL || k == 0) return;

    struct Node* current = *head;

   
    int count = 1;
    while (current->next != NULL) {
        current = current->next;
        count++;
    }

    
    k = k % count;
    if (k == 0) return;

    
    current->next = *head;

    
    struct Node* temp = *head;
    for (int i = 0; i < k - 1; i++) {
        temp = temp->next;
    }

    
    *head = temp->next;

    
    temp->next = NULL;
}


int main() {
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original List: ");
    printList(head);

    rotateLeft(&head, k);

    printf("List after rotating left by %d places: ", k);
    printList(head);

    return 0;
}

