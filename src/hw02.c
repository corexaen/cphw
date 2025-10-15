#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int low_cost(int x, int y, int n) {
    int cost1 = (n / 3) * y + (n % 3) * x;      // 3개 묶음으로 살 수 있는 최대 개수만큼 y값으로 사고 나머지는 x값으로 구매
    int cost2 = n * x;                          // 모두 x값으로 구매
    return min(cost1, cost2);                   // 두 방법 중 더 저렴한 비용 반환
}

int main() {
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    printf("%d\n", low_cost(x, y, n));
    return 0;
}