#include <stdio.h>
#include <string.h>
static inline char middle_char(const char *s) {
    return s[(strlen(s) - 1) / 2];
}

int main() {
    char str[100] = "";
    scanf("%s", str);
    printf("%c\n", middle_char(str));
    return 0;
}