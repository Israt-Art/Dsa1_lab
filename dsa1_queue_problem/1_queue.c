/*1. Implement a stack using queue.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmptyQ(struct Queue *q) {
    return q->front == q->rear;
}

void enqueue(struct Queue *q, int x) {
    q->arr[q->rear++] = x;
}

int dequeue(struct Queue *q) {
    return q->arr[q->front++];
}



struct Stack {
    struct Queue q1;
    struct Queue q2;
};

void initStack(struct Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(struct Stack *s, int x) {

    printf("Pushing %d into stack...\n", x);

    enqueue(&s->q2, x);

    while (!isEmptyQ(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    printf("Inserted %d successfully.\n", x);
}

int pop(struct Stack *s) {

    if (isEmptyQ(&s->q1)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    int x = dequeue(&s->q1);
    printf("Popped element = %d\n", x);

    return x;
}

int top(struct Stack *s) {

    if (isEmptyQ(&s->q1)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return s->q1.arr[s->q1.front];
}



int main() {

    struct Stack s;
    initStack(&s);

    int choice, val;

    while (1) {

        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(&s, val);
        }
        else if (choice == 2) {
            pop(&s);
        }
        else if (choice == 3) {
            int t = top(&s);
            if (t != -1)
                printf("Top element = %d\n", t);
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
