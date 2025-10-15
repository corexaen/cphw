#include <stdio.h>
#include <string.h>
// 여기서 인덱스는 1부터 시작
void substring(const char *source, int from, int to, char *target) {
    
    from--; // 0-based index로 변환
    while(from < to) {
        *target++ = source[from++];
    }
    *target = '\0';
    
    //strncpy(target, source + from - 1, to - from + 1);
    //target[to - from + 1] = '\0';
}

int main() {
    const char text[] = "beautiful";
    char sub[sizeof(text) / sizeof(*text)] = {0};   //잘린 문자열의 길이는 원본보다 짧거나 같음
    int l,r;
    scanf("%d %d", &l, &r);
    substring(text, l, r, sub);
    printf("%s\n", sub);
    return 0;
}