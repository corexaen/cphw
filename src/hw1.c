#include <stdio.h>

// 여기서 인덱스는 1부터 시작
void substring(const char *source, int from, int to, char *target) {
    from--; // 0-based index로 변환
    while(from < to) {
        *target++ = source[from++];
    }
    *target = '\0';
}

int main() {
    const char text[] = "beautiful";
    char sub[sizeof(text) / sizeof(*text)] = {0};
    int l,r;
    scanf("%d %d", &l, &r);
    substring(text, l, r, sub);
    printf("%s\n", sub);
    return 0;
}