#include <stdio.h>
#include <stdlib.h>

int is_same(char* S, char* T) {
    int result = 0;
    while(*S && *T) {  // 두 문자열의 끝까지
        if(*S != *T) result++;                          // 다른 문자 개수 세기
        S++;                                            // 다음 문자로 이동
        T++;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    char* S = (char*)malloc((n+1)*sizeof(char));
    char* T = (char*)malloc((n+1)*sizeof(char));
    scanf(" %s %s", S, T);
    printf("%d\n", is_same(S, T));
    free(S);
    free(T);
    return 0;
}