#include <stdio.h>
#include <string.h>
void block_cipher(unsigned char *block, const unsigned char *key) {
    for (int i = 0; i < 8; i++) {
        block[i] ^= key[i];
    }
}
void ecb_encrypt(unsigned char *plaintext, int length, const unsigned char *key) {
    for (int i = 0; i < length; i += 8) {
        block_cipher(plaintext + i, key);
    }
}
void cbc_encrypt(unsigned char *plaintext, int length, const unsigned char *key, unsigned char *iv) {
    for (int i = 0; i < length; i += 8) {
        for (int j = 0; j < 8; j++) {
            plaintext[i + j] ^= iv[j];
        }
        block_cipher(plaintext + i, key);
        memcpy(iv, plaintext + i, 8);
    }
}
void cfb_encrypt(unsigned char *plaintext, int length, const unsigned char *key, unsigned char *iv) {
    for (int i = 0; i < length; i += 8) {
        block_cipher(iv, key);
        for (int j = 0; j < 8; j++) {
            plaintext[i + j] ^= iv[j];
        }
        memcpy(iv, plaintext + i, 8);
    }
}

int main() {
    unsigned char key[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    unsigned char iv[8] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};

    unsigned char plaintext[] = "vignesh";
    int length = strlen((char *)plaintext);
    unsigned char ecb_ciphertext[length];
    memcpy(ecb_ciphertext, plaintext, length);
    ecb_encrypt(ecb_ciphertext, length, key);
    unsigned char cbc_ciphertext[length];
    memcpy(cbc_ciphertext, plaintext, length);
    cbc_encrypt(cbc_ciphertext, length, key, iv);
    unsigned char cfb_ciphertext[length];
    memcpy(cfb_ciphertext, plaintext, length);
    cfb_encrypt(cfb_ciphertext, length, key, iv);

    printf("Plaintext: %s\n", plaintext);
    printf("ECB Ciphertext: ");
    for (int i = 0; i < length; i++) {
        printf("%02x ", ecb_ciphertext[i]);
    }
    printf("\n");

    printf("CBC Ciphertext: ");
    for (int i = 0; i < length; i++) {
        printf("%02x ", cbc_ciphertext[i]);
    }
    printf("\n");

    printf("CFB Ciphertext: ");
    for (int i = 0; i < length; i++) {
        printf("%02x ", cfb_ciphertext[i]);
    }
    printf("\n");
    return 0;
}
