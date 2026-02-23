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

    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("Enter position to create cycle (enter -1 for no cycle): ");
    scanf("%d", &pos);

    if (pos != -1) {
        struct Node* temp = head;
        struct Node* cycleNode = NULL;
        int count = 0;
        while (temp->next != NULL) {
            if (count == pos)
                cycleNode = temp;
            temp = temp->next;
            count++;
        }
        
        temp->next = cycleNode;
    }

    hasCycle(head);

    return 0;
}

