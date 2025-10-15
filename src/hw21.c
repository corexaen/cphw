#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CL(char* str, char* buff) {
    while(*str != '\0') {
        if(*str >= 'A' && *str <= 'Z') {
            *(buff++) = *str;
        }
        str++;
    }
}

int main() {
    char str[101] = "";
    scanf("%100s", str);
    char* buff = (char*)malloc(strlen(str) + 1);
    memset(buff, 0, strlen(str) + 1);
    CL(str, buff);
    if(*buff == '\0')
        printf("Nothing\n");
    else
        printf("%s\n", buff);
    free(buff);
    return 0;
}