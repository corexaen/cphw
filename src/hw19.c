#include <stdio.h>

int is_short(char* str, int minimum_len) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(i >= minimum_len - 1) return 0;  // 길이가 minimum_len 이상이면 0 반환
    }
    return 1;                               // 길이가 minimum_len 미만이면 1 반환
}

int main() {
    char str[101] = "";
    int l;
    scanf("%s %d", str, &l);
    if(!is_short(str, l)) printf("YES\n");
    else printf("NO\n");
    return 0;
}