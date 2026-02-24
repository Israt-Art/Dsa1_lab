/*2. Reverse the elements of a queue.
Input: q[ ] = {10, 20, 30, 40, 50, 60}
Output: q[ ] = {60, 50, 40, 30, 20, 10}*/

#include <stdio.h>

#define MAX 100



struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(struct Queue *q) {
    return q->front == q->rear;
}

void enqueue(struct Queue *q, int x) {
    q->arr[q->rear++] = x;
}

int dequeue(struct Queue *q) {
    return q->arr[q->front++];
}

void printQueue(struct Queue *q) {

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i < q->rear; i++)
        printf("%d ", q->arr[i]);

    printf("\n");
}



void reverseQueue(struct Queue *q) {

    int stack[MAX];
    int top = -1;


    while (!isEmpty(q)) {
        stack[++top] = dequeue(q);
    }


    while (top != -1) {
        enqueue(q, stack[top--]);
    }
}



int main() {

    struct Queue q;
    initQueue(&q);

    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter queue elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    printf("Original queue:\n");
    printQueue(&q);

    reverseQueue(&q);

    printf("Queue after reversing:\n");
    printQueue(&q);

    return 0;
}
