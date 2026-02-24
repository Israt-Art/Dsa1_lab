/*determine cycle*/


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

void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("YES\n");
            return;
        }
    }

    printf("NO\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("Enter position to create cycle (0-based, -1 for no cycle): ");
    scanf("%d", &pos);

    if (pos != -1 && head != NULL) {

        struct Node *temp = head;
        struct Node *cycleNode = NULL;
        int count = 0;

        while (temp != NULL) {

            if (count == pos)
                cycleNode = temp;

            if (temp->next == NULL)
                break;

            temp = temp->next;
            count++;
        }

        if (cycleNode != NULL)
            temp->next = cycleNode;
    }

    printf("Cycle present? ");
    hasCycle(head);

    return 0;
}
