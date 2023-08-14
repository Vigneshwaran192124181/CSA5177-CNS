#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100

// Function to convert a character to its corresponding numeric value (A=0, B=1, ..., Z=25)
int charToNum(char c) {
    return c - 'A';
}

// Function to convert a numeric value to its corresponding character (0=A, 1=B, ..., 25=Z)
char numToChar(int num) {
    return num + 'A';
}

// Function to perform matrix multiplication for encryption/decryption
void matrixMultiply(int keyMatrix[][3], int inputVector[], int resultVector[], int dimension) {
    for (int i = 0; i < dimension; i++) {
        resultVector[i] = 0;
        for (int j = 0; j < dimension; j++) {
            resultVector[i] += keyMatrix[i][j] * inputVector[j];
        }
        resultVector[i] %= 26;  // Modulus 26 to wrap around the alphabet
    }
}

// Function to encrypt the plaintext using the Hill cipher
void hillEncrypt(int keyMatrix[][3], char plaintext[], char ciphertext[], int dimension) {
    int plaintextLength = strlen(plaintext);
    int inputVector[3], resultVector[3];

    for (int i = 0; i < plaintextLength; i += dimension) {
        for (int j = 0; j < dimension; j++) {
            inputVector[j] = charToNum(plaintext[i + j]);
        }

        matrixMultiply(keyMatrix, inputVector, resultVector, dimension);

        for (int j = 0; j < dimension; j++) {
            ciphertext[i + j] = numToChar(resultVector[j]);
        }
    }
    ciphertext[plaintextLength] = '\0';
}

int main() {
    int keyMatrix[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; // Example key matrix
    int dimension = 3;

    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    hillEncrypt(keyMatrix, plaintext, ciphertext, dimension);

    printf("Encrypted ciphertext: %s\n", ciphertext);

    return 0;
}
