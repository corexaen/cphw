#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_UPC(char* source, int len, char* target) {
    const char* UPC = "UPC";
    if(len == 1) {
        memcpy(target, UPC, 3);
        target[3] = *source;
        memcpy(target + 4, UPC, 3);
    }
    else {
        *(target++) = *(source++);
        memcpy(target, UPC, 3);
        target += 3;
        for(int i = 1; i < len - 1; i++) {
            *(target++) = *(source++);
        }
        memcpy(target, UPC, 3);
        target += 3;
        *(target++) = *(source++);
        *target = '\0';
    }
}

int main() {
    char input[101] = "";
    scanf("%s", input);
    int n = strlen(input);
    char* str = (char*)malloc(n + 7);
    add_UPC(input,n,str);
    printf("%s", str);
}