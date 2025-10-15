#include <stdio.h>
static inline char get_alphabet(int N, int X) {
    return (char)(((X + (N-1)) / N) + 'A' - 1);  // 올림연산으로 X번째 알파벳 계산
}
int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    printf("%c\n", get_alphabet(N, X));
    return 0;
}