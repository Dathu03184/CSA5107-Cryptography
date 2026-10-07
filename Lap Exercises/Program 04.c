#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char text[100], key[100], cipher[100];
    int i, j = 0, shift;
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key: ");
    scanf("%99s", key);
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            shift = toupper(key[j % strlen(key)]) - 'A';
            if (text[i] >= 'A' && text[i] <= 'Z')
                cipher[i] = (text[i] - 'A' + shift) % 26 + 'A';
            else
                cipher[i] = (text[i] - 'a' + shift) % 26 + 'a';
            j++;
        }
        else {
            cipher[i] = text[i];
        }
    }
    cipher[i] = '\0';
    printf("Encrypted text: %s", cipher);
    return 0;
}