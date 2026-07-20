#include <stdio.h>
#include <string.h>

void xorOperation(char *dividend, char *divisor, int start) {
    int divisorLen = strlen(divisor);
    for (int i = 0; i < divisorLen; i++) {
        dividend[start + i] =
            (dividend[start + i] == divisor[i]) ? '0' : '1';
    }
}

void computeCRC(char *data, char *divisor, char *remainder) {
    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);

    char temp[200];
    strcpy(temp, data);

    for (int i = 0; i <= dataLen - divisorLen; i++) {
        if (temp[i] == '1') {
            xorOperation(temp, divisor, i);
        }
    }

    // Copy last (divisorLen-1) bits as remainder
    for (int i = 0; i < divisorLen - 1; i++) {
        remainder[i] = temp[dataLen - divisorLen + 1 + i];
    }
    remainder[divisorLen - 1] = '\0';
}

int isZero(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '0')
            return 0;
    }
    return 1;
}

int main() {
    char data[100], divisor[20];
    char appendedData[200], remainder[20];

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator polynomial: ");
    scanf("%s", divisor);

    int dataLen = strlen(data);
    int divisorLen = strlen(divisor);

    // Append zeros to data
    strcpy(appendedData, data);
    for (int i = 0; i < divisorLen - 1; i++) {
        appendedData[dataLen + i] = '0';
    }
    appendedData[dataLen + divisorLen - 1] = '\0';

    // Compute CRC remainder
    computeCRC(appendedData, divisor, remainder);

    printf("CRC Remainder: %s\n", remainder);

    // Create transmitted data
    strcat(data, remainder);
    printf("Transmitted Data: %s\n", data);

    // Receiver Side
    char received[200];
    printf("\nEnter received data: ");
    scanf("%s", received);

    char checkRemainder[20];
    computeCRC(received, divisor, checkRemainder);

    if (isZero(checkRemainder))
        printf("No Error Detected.\n");
    else
        printf("Error Detected!\n");

    return 0;
}