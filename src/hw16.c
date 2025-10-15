#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_last_word(const char* str, int len, const char* word) {
    if(len < strlen(word)) return 1;                                // 단어 길이보다 입력 문자열 길이가 짧으면 false
    return strcmp(str + (len - strlen(word)), word);                // 입력 문자열의 끝에서 단어 길이만큼 떨어진 위치부터 비교
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