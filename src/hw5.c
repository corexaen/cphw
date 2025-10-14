#include <stdio.h>
static inline unsigned int next_olympic_year(unsigned int year) {
/*
    ((year  + 2u                                // mod 4 계산을 위해 2를 더함
            + (4u - 1u)) & ~0b11u)              // 4의 배수로 올림
      - 2u;                                     // 다시 2를 빼서 원래 값으로 복원
*/
    return ((year + 5u) & ~3u) - 2u;
}
int main() {
    unsigned int y;
    scanf("%u", &y);
    printf("%u\n", next_olympic_year(y));
    return 0;
}