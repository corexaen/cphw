#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int painted(int l1, int r1, int l2, int r2) {
    return max(min(r1, r2) - max(l1, l2) + 1 , 0);
}

int main() {
    int l1, r1, l2, r2;
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    printf("%d\n", painted(l1, r1, l2, r2));
    return 0;
}