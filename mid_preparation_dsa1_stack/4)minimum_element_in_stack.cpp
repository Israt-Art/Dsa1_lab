#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Stack {
    int arr[MAX];
    int top;
};


void initStack(struct Stack* stack) {
    stack->top = -1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}


int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current stack elements:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}


int findMin(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    int min = stack->arr[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->arr[i] < min) {
            min = stack->arr[i];
        }
    }
    return min;
}


int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, value, n;

    printf("Enter initial number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    display(&stack);
    printf("Minimum element: %d\n", findMin(&stack));

    
    printf("\nAfter removing two elements:\n");
    pop(&stack);
    pop(&stack);
    display(&stack);
    printf("Minimum element: %d\n", findMin(&stack));

    printf("\nEnter element to add: ");
    scanf("%d", &value);
    push(&stack, value);

    printf("\nAfter adding one element:\n");
    display(&stack);
    printf("Minimum element: %d\n", findMin(&stack));

    return 0;
}

