#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CL(char* str, char* buff) {
    while(*str != '\0') {
        if(*str >= 'A' && *str <= 'Z') {    // 대문자이면
            *(buff++) = *str;               // 저장
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
    if(*buff == '\0')               // 저장된 문자가 없으면
        printf("Nothing\n");
    else
        printf("%s\n", buff);
    free(buff);
    return 0;
}