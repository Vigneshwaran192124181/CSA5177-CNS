#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void print_hex(const unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    char message[] = "Hello, SHA-256!"; // Input message

    unsigned char hash[SHA256_DIGEST_LENGTH]; // SHA-256 hash will be stored here

    SHA256((unsigned char *)message, strlen(message), hash);

    printf("Message: %s\n", message);
    printf("SHA-256 Hash: ");
    print_hex(hash, SHA256_DIGEST_LENGTH);

    return 0;
}
