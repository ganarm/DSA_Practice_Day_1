// Q.4 
/*
  q. chi requirement hich he ka check krshil aani mla sanghsil 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

// Stack ADT function declarations
void push(int);
int pop();
int peek();
int isFull();
int isEmpty();
void init();

// Stack variables
int stack[MAX], top = -1;

// Stack functions
int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

void init() {
    top = -1;
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}

// Function for infix to postfix conversion
void infixToPostfix(char *exp, char *result) {
    int i = 0, k = 0;
    char symbol;
    while ((symbol = exp[i++]) != '\0') {
        if (isalnum(symbol)) {
            result[k++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (!isEmpty() && peek() != '(') {
                result[k++] = pop();
            }
            pop();  // Pop the '('
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(symbol)) {
                result[k++] = pop();
            }
            push(symbol);
        }
    }
    
    while (!isEmpty()) {
        result[k++] = pop();
    }
    result[k] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i = 0;
    char symbol;
    int op1, op2, result;
    
    while ((symbol = exp[i++]) != '\0') {
        if (isdigit(symbol)) {
            push(symbol - '0');  // Convert char to int
        } else {
            op2 = pop();
            op1 = pop();
            switch (symbol) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = op1 ^ op2; break; // For exponentiation (power)
                default: result = 0;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char infix[MAX], postfix[MAX];
    int result;
    
    // Input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    // Evaluate postfix expression
    result = evaluatePostfix(postfix);
    printf("Evaluation of Postfix Expression: %d\n", result);

    return 0;
}
/*
Enter an infix expression: 4+8/7-6-6*6+3+5
Postfix Expression: 487/+6-66*-3+5+
Evaluation of Postfix Expression: -29
*/
