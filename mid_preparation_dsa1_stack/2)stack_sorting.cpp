#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;


void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++(*top)] = value;
    }
}


int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[(*top)--];
    }
}

int isEmpty(int top) {
    return (top == -1);
}


void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


void sortStack() {
    int tempStack[MAX];
    int tempTop = -1;
    int temp;

    while (!isEmpty(top)) {
        
        temp = pop(stack, &top);

        
        while (!isEmpty(tempTop) && tempStack[tempTop] > temp) {
            push(stack, &top, pop(tempStack, &tempTop));
        }

        
        push(tempStack, &tempTop, temp);
    }

    
    while (!isEmpty(tempTop)) {
        push(stack, &top, pop(tempStack, &tempTop));
    }

    printf("Stack sorted successfully.\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Sorting Menu ---\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Sort Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;
            case 2:
                display(stack, top);
                break;
            case 3:
                sortStack();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

