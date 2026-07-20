#include <stdio.h> 

int main () {
    int value[5];

    printf ("Enter values for integer array: \n");

    for (int i = 0; i < 5; i++) {
        printf ("Value %d: ", i);
        scanf ("%d", &value[i]);
    }

    printf ("You entered: \n");

    for (int i = 0; i < 5; i++) 
        printf ("%d ", value[i]);

    return 0;
}