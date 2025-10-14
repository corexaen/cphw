#include <stdio.h>

int is_full_house(const int *cards) {
    unsigned int hands = 0;
    for (int i = 0; i < 5; i++) {
        int shift = (cards[i] - 1) * 2;
        unsigned int c = (hands >> shift) & 3;
        hands = (hands & ~(3u << shift)) | (((c + 1) & 3u) << shift);
    }

    int f2 = 0, f3 = 0;
    for (int i = 0; i < 13; i++) {
        int c = (hands >> (i * 2)) & 3;
        f2 |= (c == 2);
        f3 |= (c == 3);
    }
    return f2 & f3;
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