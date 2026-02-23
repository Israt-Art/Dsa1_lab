#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void insertNode(struct Node* root) {
    int data, choice;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    struct Node* current = root;
    while (1) {
        printf("At Node with data %d\n", current->data);
        printf("Where do you want to insert the new node?\n");
        printf("1. Left\n2. Right\n");
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


void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    int data, n, i;
    struct Node* root = NULL;

    printf("Enter data for root node: ");
    scanf("%d", &data);
    root = createNode(data);

    printf("How many nodes do you want to insert? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        insertNode(root);
    }

    printf("\nIn-order Traversal of the Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("\nTotal nodes in the binary tree: %d\n", countNodes(root));

    return 0;
}
