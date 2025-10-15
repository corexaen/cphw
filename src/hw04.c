#include <stdio.h>

int is_full_house(const int *cards) {
    unsigned int hands = 0;                                             // 각 카드의 개수를 2비트씩 저장하는 배열
    for (int i = 0; i < 5; i++) {
        int shift = (cards[i] - 1) * 2;
        unsigned int c = (hands >> shift) & 3;
        hands = (hands & ~(3u << shift)) | (((c + 1) & 3u) << shift);   // 2비트 단위로 카드 개수 저장
    }

    int f2 = 0, f3 = 0;
    for (int i = 0; i < 13; i++) {
        int c = (hands >> (i * 2)) & 3;
        f2 |= (c == 2);                                                 // 2장이면 f2 플래그 설정
        f3 |= (c == 3);                                                 // 3장이면 f3 플래그 설정
    }
    return f2 & f3;                                                    // 2장과 3장 플래그가 모두 설정되어야 풀하우스
}
int main() {
    int cards[5];
    for(int i = 0; i < 5; i++) {
        scanf("%d", &cards[i]);
    }
    if(is_full_house(cards)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}