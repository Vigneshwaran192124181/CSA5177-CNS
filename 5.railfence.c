  #include <stdio.h>
#include <string.h>

void railFenceEncrypt(char *plaintext, int rails, char *ciphertext) {
    int length = strlen(plaintext);
    int cycleLength = 2 * (rails - 1);

    for (int i = 0; i < rails; i++) {
        int index = i;
        int step1 = 2 * (rails - i - 1);
        int step2 = cycleLength - step1;

        int stepFlag = 0;

        while (index < length) {
            ciphertext[strlen(ciphertext)] = plaintext[index];

            if (step1 > 0 && step2 > 0) {
                if (stepFlag == 0) {
                    index += step1;
                    stepFlag = 1;
                } else {
                    index += step2;
                    stepFlag = 0;
                }
            } else if (step1 == 0) {
                index += step2;
            } else {
                index += step1;
            }
        }
    }

    ciphertext[length] = '\0';
}

int main() {
    char plaintext[1000];
    int rails;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove the newline character

    printf("Enter the number of rails: ");
    scanf("%d", &rails);

    char ciphertext[1000] = "";

    railFenceEncrypt(plaintext, rails, ciphertext);

    printf("Encrypted ciphertext: %s\n", ciphertext);

    return 0;
}
