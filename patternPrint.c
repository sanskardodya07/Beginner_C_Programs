#include <stdio.h>

void diamond (int num);
void hollowDiamond (int num);
void hollowRect (int height,int width);
void hollowSquare (int num);
void rectangle (int height,int width);
void square (int num);

int main () {
    int num, choice, height, width;

    do {
        printf ("Enter height of diamond(odd): ");
        scanf ("%d", &num);
    } while (num % 2 == 0);
    do {
        printf ("Enter 1 for solid diamond.\nEnter 2 for hollow diamond.\n: ");
        scanf ("%d", &choice);
    } while (choice != 1 && choice != 2);
    
    if (choice == 1) {
        diamond (num);
    } else {
        hollowDiamond (num);
    }

    printf ("Enter size of square to be printed: ");
    scanf ("%d", &num);
    do {
        printf ("Enter 1 for solid square.\nEnter 2 for hollow square.\n: ");
        scanf ("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1) {
        square (num);
    } else {
        hollowSquare (num);
    }

    printf ("Enter height of rectangle to be printed: ");
    scanf ("%d", &height);
    printf ("Enter width of rectangle to be printed: ");
    scanf ("%d", &width);
    do {
        printf ("Enter 1 for solid square.\nEnter 2 for hollow square.\n: ");
        scanf ("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1) {
        rectangle (height, width);
    } else {
        hollowRect (height, width);
    }
}

void diamond (int num) {
    num = (num + 1) / 2;

    for (int i = 0; i < num; i++) {
        for (int j = num - i - 1; j > 0; j--) {
            printf (" ");
        }
        for (int j = i + 1; j > 0; j--) {
            printf ("*");
        }
        for (int j = i; j > 0; j--) {
            printf ("*");
        }
        printf ("\n");
    }

    num = num - 1;
    
    for (int i = num; i > 0; i--) {
        for (int j = num - i + 1; j > 0; j--) {
            printf (" ");
        }
        for (int j = i; j > 0; j--) {
            printf ("*");
        }
        for (int j = i - 1; j > 0; j--) {
            printf ("*");
        }
        printf ("\n");
    }
}

void hollowDiamond (int num) {
    num = (num + 1) / 2;

    for (int i = 0; i < num; i++) {
        for (int j = num - i - 1; j > 0; j--) {
            printf (" ");
        }
        printf ("*");
        for (int j = (2 * i) - 1; j > 0; j--) {
            printf (" ");
        }
        if (i != 0) {
            printf ("*");
        }
        printf ("\n");
    }

    num = num - 1;
    
    for (int i = num; i > 0; i--) {
        for (int j = num - i + 1; j > 0; j--) {
            printf (" ");
        }
        printf ("*");
        for (int j = (2 * (i - 1)) - 1; j > 0; j--) {
            printf (" ");
        }
        if (i != 1) {
            printf ("*");
        }
        printf ("\n");
    }
}

void hollowSquare (int num) {
    for (int i = 1; i <= num; i++) {
        printf ("* ");
    }
    printf ("\n");
    for (int i = 1; i <= num - 2; i++) {
        printf ("* ");
        for (int j = 1; j <= num - 2; j++) {
            printf ("  ");
        }
        printf ("* ");
        printf ("\n");
    }
    if (num != 1){
        for (int i = 1; i <= num; i++) {
            printf ("* ");
        }
    }
    printf ("\n");
}

void hollowRect (int height,int width) {
    for (int i = 1; i <= width; i++) {
        printf ("* ");
    }
    printf ("\n");
    for (int i = 1; i <= height - 2; i++) {
        printf ("* ");
        for (int j = 1; j <= width - 2; j++) {
            printf ("  ");
        }
        printf ("* ");
        printf ("\n");
    }
    if (height != 1){
        for (int i = 1; i <= width; i++) {
            printf ("* ");
        }
    }
    printf ("\n");
}

void square (int num) {
    for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            printf ("* ");
        }
        printf ("\n");
    }
}

void rectangle (int height, int width) {
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            printf ("* ");
        }
        printf ("\n");
    }
}