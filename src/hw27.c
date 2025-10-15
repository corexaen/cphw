#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void changeC(char* str, char a, char b) {
    while(*str != '\0') {
        *str = *str == a ? a : b;
        str++;
    }
}

int main() {
    int n;
    char c1, c2;
    scanf("%d %c %c", &n, &c1, &c2);
    char* str = (char*)malloc((n + 1) * sizeof(char));
    scanf(" %s", str);
    changeC(str, c1, c2);
    printf("%s\n", str);
    return 0;
}