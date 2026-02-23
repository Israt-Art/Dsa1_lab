#include <stdio.h>
#define MAX 100

int main() {
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;
    int n, i;

    // Take number of elements
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    // Input queue elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    // Push queue elements to stack
    for(i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Pop stack elements back to queue (reversed)
    for(i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    printf("Reversed Queue: ");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}

