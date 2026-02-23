#include <stdio.h>
#include <stdlib.h>


#define max(a, b) ((a) > (b) ? (a) : (b))


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

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}


int treeHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}


int sumNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}


int nodeDepth(struct Node* root, int target, int depth) {
    if (root == NULL)
        return -1; 

    if (root->data == target)
        return depth;

    int leftDepth = nodeDepth(root->left, target, depth + 1);
    int rightDepth = nodeDepth(root->right, target, depth + 1);

    return (leftDepth != -1) ? leftDepth : rightDepth;
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
    printf("Total leaf nodes in the binary tree: %d\n", countLeafNodes(root));
    printf("Height of the binary tree: %d\n", treeHeight(root));
    printf("Sum of all nodes in the binary tree: %d\n", sumNodes(root));

    
    int targetNode;
    printf("Enter the node value to find its depth: ");
    scanf("%d", &targetNode);

    int depth = nodeDepth(root, targetNode, 0);
    if (depth != -1) {
        printf("Depth of node with value %d: %d\n", targetNode, depth);
    } else {
        printf("Node with value %d not found in the tree.\n", targetNode);
    }

    return 0;
}
