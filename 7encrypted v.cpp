#include <string.h>
#include<stdio.h>
#define BLOCK_SIZE 16
void encryptBlock(char *block) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] = (block[i] + 1) % 256;
    }
}
int main() {
    char plaintext[] = "HELLOELECTRONICCB";
    int textLength = strlen(plaintext);
    int padding = BLOCK_SIZE - (textLength % BLOCK_SIZE);
    if (padding != BLOCK_SIZE) {
        textLength += padding;
        memset(plaintext + strlen(plaintext), 0, padding);
    }
    for (int i = 0; i < textLength; i += BLOCK_SIZE) {
        encryptBlock(plaintext + i);
    }
    printf("Encrypted ciphertext");
    for (int i = 0; i < textLength; i++) {
        printf("%02X ", (unsigned char)plaintext[i]);
    }
    printf("\n");
}
