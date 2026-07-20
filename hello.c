#include <stdio.h>
#include <string.h>

int main () {
    char name[50];

    printf ("Enter your name: ");
    fgets (name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf ("Hello, %s!", name);

    return 0;
}