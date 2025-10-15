#include <stdio.h>

char only_char(const char* str, int len) {
    char count[256] = {0};
    for (int i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];
        if(count[ch] < 2) {                             // 2 이상이면 더 이상 셀 필요 없음
            count[ch]++;                                // 각 문자의 등장 횟수 세기
        }
    }
    for (int i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (count[ch] == 1) {                           // 등장 횟수가 1인 문자 반환
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