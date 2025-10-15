#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void substring(const char *source, int c1, int c2, char *target) {
    int to = strlen(source) - c2;
    while(c1 < to) {                            // c1부터 시작 length - c2 까지
        *target++ = source[c1++];
    }
    *target = '\0';
}

int main() {
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);
    char* str = (char*)malloc((n+1)*sizeof(char));
    char* result = (char*)malloc((n+1)*sizeof(char));
    scanf("%s", str);
    substring(str, a, b, result);
    printf("%s\n", result);
    free(str);
    free(result);
    return 0;
}