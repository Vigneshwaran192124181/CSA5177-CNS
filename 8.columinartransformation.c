#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void encryptMessage(char *msg, int key[], int col) {
    int len = strlen(msg);
    int row = (len + col - 1) / col;

    char matrix[row][col];

    int index = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (index < len) {
                matrix[i][j] = msg[index++];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (isalpha(matrix[i][key[j]]) || matrix[i][key[j]] == ' ') {
                printf("%c", matrix[i][key[j]]);
            }
        }
    }
}

void decryptMessage(char *msg, int key[], int col) {
    int len = strlen(msg);
    int row = (len + col - 1) / col;

    char matrix[row][col];

    int index = 0;
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            matrix[i][key[j]] = msg[index++];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != ' ') {
                printf("%c", matrix[i][j]);
            }
        }
    }
}

int main() {
    char msg[MAX_SIZE] = "HELLOCOLUMNT";  // Example plaintext
    int key[] = {2, 0, 1};               // Example key (column order)
    int col = sizeof(key) / sizeof(key[0]);

    printf("Plaintext: %s\n", msg);

    printf("Encrypted: ");
    encryptMessage(msg, key, col);
    printf("\n");

    printf("Decrypted: ");
    decryptMessage(msg, key, col);
    printf("\n");

    return 0;
}
