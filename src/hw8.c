#include <stdio.h>

char only_char(const char* str, int len) {
    char count[256] = {0};
    for (int i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];
        if(count[ch] < 2) {
            count[ch]++;
        }
    }
    for (int i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (count[ch] == 1) {
            return ch;
        }
    }
    return '\0';
}
int main() {
    char input[4] = {0,};
    scanf("%3s", input);
    char result = only_char(input, 3);
    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }
    return 0;
}