#include <stdio.h>

int main () {
    int num1, num2, num3;
    printf ("Enter three no.s to compare them \n");
    printf ("1: ");
    scanf ("%d", &num1);
    printf ("2: ");
    scanf ("%d", &num2);
    printf ("3: ");
    scanf ("%d", &num3);

    if (num1 >= num2 && num1 >= num3) {
        printf ("%d is the greatest.\n", num1);
    } else if (num2 >= num3) {
        printf ("%d is the greatest.\n", num2);
    } else {
        printf ("%d is the greatest.\n", num3);
    }

    return 0;
}