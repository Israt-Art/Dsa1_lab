#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h> 

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


int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}


int evaluatePostfix(char expr[]) {
    int i = 0, op1, op2, result;

    while (expr[i] != '\0') {
        
        if (isdigit(expr[i])) {
            push(expr[i] - '0');  
        }
        else {
            
            op2 = pop();
            op1 = pop();

            switch (expr[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default: printf("Invalid operator %c\n", expr[i]); return -1;
            }
            push(result);
        }
        i++;
    }

    return pop();
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+9-): ");
    scanf("%s", expression);

    int finalResult = evaluatePostfix(expression);

    printf("Result of the expression: %d\n", finalResult);

    return 0;
}

