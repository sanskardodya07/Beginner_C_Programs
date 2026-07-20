#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluate (char postfix[]);
void postfix (char infix[]);

int main () {
    int choice, result;
    char equation[100], temp[100];

    printf ("Enter the arithematic equation to be calculated\n(Note: Every element must be space seperated, Max capacity 100 charcaters):");
    fgets (equation, 100, stdin);
    equation[strcspn(equation, "\n")] = '\0';

    strcpy(temp, equation);
    postfix (equation);

    printf ("\n%s", equation);
    result = evaluate (equation);

    printf ("\n%s = %d\n", temp, result);
    return 0;
}

int evaluate (char postfix[]) {
    int stack[52];
    int top = -1, j = -1, a, b;
    char temp[20];

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == ' ') {
            if (j >= 0) {
                temp[++j] = '\0';
                stack[++top] = atoi(temp);
                j = -1;
            }
        }
        else if (isdigit(postfix[i])) {
            temp[++j] = postfix[i];
        }
        else {
            b = stack[top--];
            a = stack[top--];

            switch (postfix[i]) {
                case '+':
                    stack[++top] = a + b;
                    break;
                case '-':
                    stack[++top] = a - b;
                    break;
                case '*':
                    stack[++top] = a * b;
                    break;
                case '/':
                    stack[++top] = a / b;
                    break;    
            }
        }
    }
    return stack[0];
}

void postfix(char infix[]) { 
    int top_postfix = -1, top_operator = -1;
    char output[100], operator[100];
    
    for (int peek = 0; infix[peek] != '\0'; peek++) {
        if (infix[peek] == ' ') {
            continue;
        }
        else if (infix[peek] == '(') {
            operator[++top_operator] = infix[peek];
        }
        else if (infix[peek] == ')') {
            while (top_operator >= 0 && operator[top_operator] != '(') {
                output[++top_postfix] = operator[top_operator--];
                output[++top_postfix] = ' ';
            }
            top_operator--;
        }
        else if (infix[peek] == '*' || infix[peek] == '/') {
            while (top_operator >= 0 && operator[top_operator] != '(' &&
                  (operator[top_operator] == '*' || operator[top_operator] == '/')) {
                output[++top_postfix] = operator[top_operator--];
                output[++top_postfix] = ' ';
            }
            operator[++top_operator] = infix[peek];
        }
        else if (infix[peek] == '+' || infix[peek] == '-') {
            while (top_operator >= 0 && operator[top_operator] != '(') {
                output[++top_postfix] = operator[top_operator--];
                output[++top_postfix] = ' ';
            }
            operator[++top_operator] = infix[peek];
        }
        else {
            while (infix[peek] != ' ' && infix[peek] != '\0') {
                output[++top_postfix] = infix[peek++];
            }
            output[++top_postfix] = ' ';
            peek--;
        }
    }

    while (top_operator >= 0) {
        output[++top_postfix] = operator[top_operator--];
        output[++top_postfix] = ' ';
    }
    output[++top_postfix] = '\0';
    
    strcpy(infix, output);
}