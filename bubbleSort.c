#include <stdio.h>

void bubbleSort (int array[], int max);

int main () {
    int num;
    printf ("Enter size of array: ");
    scanf ("%d", &num);

    int array[num];

    for (int i = 0; i < num; i++) {
        printf ("Enter Element %d: ", i + 1);
        scanf ("%d", &array[i]);
    }

    bubbleSort (array, num);
    
    for (int i = 0; i < num; i++) {
        printf ("%d, ", array[i]);
    }
}

void bubbleSort (int array[], int max) {
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}