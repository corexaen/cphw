#include <stdio.h>
#include <string.h>

const char* translate(const char* str) {
    const char* know_word[3] = {"red", "blue", "green"};
    const char* new_word[3] = {"SSS", "FFF", "MMM"};
    for (int i = 0; i < 3; i++) {
        if (strcmp(str, know_word[i]) == 0) {
            return new_word[i];
        }
    }
    return "Unknown";                               // 문자열은 .rodata에 저장됨으로 복사하지 않고 주소값만 반환
}

int main() {
    char input[11] = {0,};
    scanf("%10s", input);
    const char* output = translate(input);
    printf("%s\n", output);
    return 0;
}