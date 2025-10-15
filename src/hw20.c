#include <stdio.h>
char _404(char* str) {
    unsigned int arr = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        arr |= (1 << (str[i] - 'a'));
    }
    for(int i = 0; i < 26; i++) {
        if(!(arr & (1 << i))) return 'a' + i;
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