#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to enqueue an element
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        // Reset queue when empty
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}

// Function to display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Function to delete nth element
void deleteNth(int n) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    if (n < 1 || n > (rear - front + 1)) {
        printf("Invalid position to delete\n");
        return;
    }

    int count = 1;
    int size = rear - front + 1;

    // Use a loop to dequeue and enqueue back, skipping the nth element
    for (int i = 0; i < size; i++) {
        int temp = dequeue();
        if (count != n) {
            enqueue(temp);
        }
        count++;
    }
    printf("Deleted element at position %d\n", n);
}

// Main function
int main() {
    int n, value, position;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    printf("Queue before deletion:\n");
    display();

    printf("Enter the position to delete (1-based): ");
    scanf("%d", &position);

    deleteNth(position);

    printf("Queue after deletion:\n");
    display();

    return 0;
}

