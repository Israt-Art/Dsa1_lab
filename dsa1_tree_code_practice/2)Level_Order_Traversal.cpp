#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* queue[MAX];
int front = 0, rear = -1;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


void enqueue(struct Node* node) {
    queue[++rear] = node;
}


struct Node* dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front > rear;
}


void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    front = 0;
    rear = -1;

    enqueue(root);
    printf("\nLevel-Order Traversal: ");

    while (!isQueueEmpty()) {
        struct Node* current = dequeue();
        printf("%d ", current->data);

        if (current->left) enqueue(current->left);
        if (current->right) enqueue(current->right);
    }
    printf("\n");
}


void insertNode(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = root;
    int choice;

    while (1) {
        printf("Current Node: %d\n", current->data);
        printf("Where to insert %d? (1.Left / 2.Right): ", data);
        scanf("%d", &choice);

        if (choice == 1) {
            if (current->left == NULL) {
                current->left = newNode;
                printf("Inserted %d to the left of %d\n", data, current->data);
                break;
            } else {
                current = current->left;
            }
        } else if (choice == 2) {
            if (current->right == NULL) {
                current->right = newNode;
                printf("Inserted %d to the right of %d\n", data, current->data);
                break;
            } else {
                current = current->right;
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}


int main() {
    int data, n;

    printf("Enter data for root node: ");
    scanf("%d", &data);
    struct Node* root = createNode(data);

    printf("How many more nodes to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(root, data);
    }

    levelOrderTraversal(root);
    return 0;
}
