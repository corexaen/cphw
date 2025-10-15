#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_last_word(const char* str, int len, const char* word) {
    if(len < strlen(word)) return 1;
    return strcmp(str + (len - strlen(word)), word);
}

int main() {
    int N;
    scanf("%d", &N);
    char* input = (char*)malloc((N + 1) * sizeof(char));
    memset(input, 0, (N + 1) * sizeof(char));
    scanf("%s", input);
    if(!is_last_word(input,N,"tea")) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    free(input);
    return 0;
}