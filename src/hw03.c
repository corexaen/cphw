#include <stdio.h>
#include <string.h>
static inline char middle_char(const char *s) {
    return s[(strlen(s) - 1) / 2];                  // 문자열 길이를 구한 후 가운데 문자 반환
}

int main() {
    char str[100] = "";
    scanf("%s", str);
    printf("%c\n", middle_char(str));
    return 0;
}