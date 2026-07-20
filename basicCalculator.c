#include <stdio.h>

int main () {
    int op1, op2, result;
    char opr;

    printf ("Enter the first integer operand: ");
    scanf ("%d", &op1);

    printf ("Enter the second integer operand: ");
    scanf ("%d", &op2);
    getchar();

    printf ("Enter operator: ");
    scanf ("%c", &opr);

    switch (opr) {
        case '+':
            result = op1 + op2;
            break;

        case '-':
            result = op1 - op2;
            break;
        
        case '*':
            result = op1 * op2;
            break;

        case '/':
            result = op1 / op2;
            break;

        case '%':
            result = op1 % op2;

        default: 
            printf ("invalid input recieved....\n");
    }

    printf ("%d %c %d = %d (implicit conversioon of result in int..)", op1, opr, op2, result);

    return 0;
}