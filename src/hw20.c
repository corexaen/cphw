#include <stdio.h>
char _404(char* str) {
    unsigned int arr = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        arr |= (1 << (str[i] - 'a'));           // 등장한 문자는 1
    }
    for(int i = 0; i < 26; i++) {
        if(!(arr & (1 << i))) return 'a' + i;   // 등장하지 않은 문자 찾기
    }
    return 0;
}
int main() {
    char input[50] = "";
    scanf("%s", input);
    char result = _404(input);
    printf("%c\n", result);
    return 0;
}