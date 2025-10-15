#include <stdio.h>
#include <stdlib.h>
int is_o(char* str, int len, int left, int right) {
    for(int i=left - 1; i<right; i++) {                 // left부터 right까지
        if(str[i] != 'o') return 0;                     // 하나라도 o가 아니면 0 반환
    }
    return 1;                                           // 모두 o이면 1 반환
}

int main() {
    int n,l,r;
    scanf("%d %d %d", &n, &l, &r);
    char* str = (char*)malloc((n+1)*sizeof(char));
    scanf("%s", str);
    if(is_o(str, n, l, r)) printf("YES\n");
    else printf("NO\n");
    free(str);
    return 0;
}