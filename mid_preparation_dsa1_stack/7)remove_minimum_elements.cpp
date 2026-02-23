#include <stdio.h>
#include <limits.h>

#define MAX 100

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    top--;
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int getMin() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    int min = stack[0];
    for (int i = 1; i <= top; i++) {
        if (stack[i] < min) {
            min = stack[i];
        }
    }
    return min;
}


void removeMin() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    int min = getMin();
    int found = 0;

    
    for (int i = 0; i <= top; i++) {
        if (stack[i] == min && !found) {
            found = 1;
            for (int j = i; j < top; j++) {
                stack[j] = stack[j + 1];
            }
            top--;
            break;
        }
    }

    printf("Removed minimum element: %d\n", min);
}

int main() {
    int n, value;

    
    printf("How many elements you want to push? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    printf("\nBefore removing minimum element:\n");
    display();

    
    removeMin();

    printf("\nAfter removing minimum element:\n");
    display();

    return 0;
}

