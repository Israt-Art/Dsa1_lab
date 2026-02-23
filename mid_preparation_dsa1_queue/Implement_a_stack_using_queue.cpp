#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front, rear;
    int data[MAX];
} Queue;

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q->data[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front++];
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

typedef struct {
    Queue q1, q2;
} Stack;

void push(Stack *s, int value) {
    enqueue(&s->q2, value);
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue(&s->q1);
}

void display(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->q1.front; i <= s->q1.rear; i++) {
        printf("%d ", s->q1.data[i]);
    }
    printf("\n");
}

int main() {
    Stack s = {{0, -1}, {0, -1}};
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                printf("Popped value: %d\n", pop(&s));
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
