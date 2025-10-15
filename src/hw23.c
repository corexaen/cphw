#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void center_doubleline(char* str, int len) {
    str[(len - 1) / 2] = '=';       // 가운데 두 줄을 =로 채움
    str[len / 2] = '=';             
}

int main() {
    int n;
    scanf("%d", &n);
    char* str = (char*)malloc((n+1)*sizeof(char));
    memset(str, '-', n);
    str[n] = '\0';
    center_doubleline(str, n);
    printf("%s\n", str);
    free(str);
    return 0;
}