/* Reverse a doubly linked list
Input :  7<->12<->8<->65<->10
Output: 10<->65<->8<->12<->7
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void addNode(struct Node **head, int data) {

    struct Node *n = createNode(data);

    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void printList(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* reverseDoublyList(struct Node *head) {

    struct Node *curr = head;
    struct Node *temp = NULL;

    while (curr != NULL) {

        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    return head;
}

int main() {

    struct Node *head = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("Original list:\n");
    printList(head);

    head = reverseDoublyList(head);

    printf("Reversed list:\n");
    printList(head);

    return 0;
}