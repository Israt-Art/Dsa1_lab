#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node node;

void menu();
node* createNode();
void printList(node* head);
node* insert_head(node* head, node* nn);
node* insert_tail(node* head, node* nn);
node* insertAtNthPosition(node* head, node* nn, int n, int position);
node* delete_head(node *head);
int ListSize(node* head);
node* delete_tail(node *head);
node* delete_nth(node *head, int n, int position);
node* updateNodeValue(node* head, int position, int newValue);
void reversePrintList(node* head);
node* searchAndModifyList(node* head, int key);

int main() {
    node* head = NULL, *nn;
    printf("Use free() in C or including stdlib.h, use delete() in C++\n");
    int choice;
    menu();
    scanf("%d", &choice);

    while (choice != 0) {
        if (choice == 1) {
            printList(head);
        } else if (choice == 2) {
            nn = createNode();
            head = insert_head(head, nn);
        } else if (choice == 3) {
            nn = createNode();
            head = insert_tail(head, nn);
        } else if (choice == 4) {
            int len = ListSize(head);
            printf("List Size: %d\n\n", len);
        } else if (choice == 5) {
            nn = createNode();
            int n = ListSize(head);
            printf("Enter position: ");
            int position;
            scanf("%d", &position);
            if (position >= 1 && position <= n + 1) {
                head = insertAtNthPosition(head, nn, n, position);
            } else {
                printf("Invalid Position!\n\n");
            }
        } else if (choice == 6) {
            head = delete_head(head);
        } else if (choice == 7) {
            head = delete_tail(head);
        } else if (choice == 8) {
            int n, position;
            n = ListSize(head);
            printf("Enter position: ");
            scanf("%d", &position);
            if (position >= 1 && position <= n) {
                head = delete_nth(head, n, position);
            } else {
                printf("Invalid position\n\n");
            }
        } else if (choice == 9) {
            int position, newValue;
            printf("Enter position to update: ");
            scanf("%d", &position);
            printf("Enter new value: ");
            scanf("%d", &newValue);
            int n = ListSize(head);
            if (position >= 1 && position <= n) {
                head = updateNodeValue(head, position, newValue);
            } else {
                printf("Invalid Position!\n\n");
            }
        } else if (choice == 10) {
            printf("Reversed List:\n");
            reversePrintList(head);
            printf("\n\n");
        } else if (choice == 11) {
            int key;
            printf("Enter key to search: ");
            scanf("%d", &key);
            head = searchAndModifyList(head, key);
        } else {
            printf("Invalid Choice!\n");
        }
        menu();
        scanf("%d", &choice);
    }

    printf("\nYou pressed the Exit button!\nBye...\n");
}

void menu() {
    printf("1) Print List\n");
    printf("2) Insert Data at Head\n");
    printf("3) Insert Data at Tail\n");
    printf("4) Size of Linked List\n");
    printf("5) Insert Data at Nth Position\n");
    printf("6) Delete Head Data\n");
    printf("7) Delete Tail Data\n");
    printf("8) Delete Nth Position Data\n");
    printf("9) Update a Node Value\n");
    printf("10) Reverse the Linked List\n");
    printf("11) Search and Modify the List\n");
    printf("0) Exit\n");
    printf("Enter your choice: ");
}

node* createNode() {
    node* nn = new node();
    printf("Enter data: ");
    scanf("%d", &nn->data);
    nn->next = NULL;
    return nn;
}

void printList(node* head) {
    node* temp = head;
    printf("Data in Linked List:\n\n");
    if (temp == NULL) {
        printf("No Data Found!\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n\n");
}

node* insert_head(node* head, node* nn) {
    if (head != NULL) {
        nn->next = head;
    }
    head = nn;
    printf("Node inserted at Head!\n\n");
    return head;
}

node* insert_tail(node* head, node* nn) {
    if (head == NULL) {
        head = insert_head(head, nn);
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
    printf("Node inserted at Tail!\n\n");
    return head;
}

node* insertAtNthPosition(node* head, node* nn, int n, int position) {
    if (position == 1) {
        head = insert_head(head, nn);
    } else if (position == n + 1) {
        head = insert_tail(head, nn);
    } else {
        node* temp = head;
        for (int i = 1; i <= position - 2; i++) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
    printf("Data inserted at Nth position!\n\n");
    return head;
}

node* delete_head(node* head) {
    if (head == NULL) {
        printf("Nothing to delete\n\n");
    } else {
        node* temp = head;
        head = head->next;
        delete(temp);
    }
    printf("Node deleted!\n\n");
    return head;
}

int ListSize(node* head) {
    int counter = 0;
    node* temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

node* delete_tail(node* head) {
    int n = ListSize(head);
    if (n <= 1) {
        head = delete_head(head);
    } else {
        node* temp = head;
        for (int i = 1; i <= n - 2; i++) {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    printf("Tail Node deleted!\n\n");
    return head;
}

node* delete_nth(node* head, int n, int position) {
    if (position == 1) {
        head = delete_head(head);
    } else if (position == n) {
        head = delete_tail(head);
    } else {
        node* temp = head;
        for (int i = 1; i <= position - 2; i++) {
            temp = temp->next;
        }
        node* del = temp->next;
        temp->next = del->next;
        delete(del);
    }
    printf("%d position Node deleted!\n\n", position);
    return head;
}

node* updateNodeValue(node* head, int position, int newValue) {
    node* temp = head;
    for (int i = 1; i < position; i++) {
        temp = temp->next;
    }
    temp->data = newValue;
    printf("Node updated at position %d.\n\n", position);
    printList(head);
    return head;
}

void reversePrintList(node* head) {
    if (head == NULL) {
        return;
    }
    reversePrintList(head->next);
    printf("%d ", head->data);
}

node* searchAndModifyList(node* head, int key) {
    node* temp = head;
    node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                head = delete_head(head);
            } else {
                prev->next = temp->next;
                delete(temp);
            }
            printf("Key is found. Deleting...\n");
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key not found. Inserting at the end...\n");
    node* nn = createNode();
    nn->data = key;
    head = insert_tail(head, nn);
    return head;
}
