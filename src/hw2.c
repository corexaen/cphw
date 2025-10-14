#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int low_cost(int x, int y, int n) {
    int cost1 = (n / 3) * y + (n % 3) * x;
    int cost2 = n * x;
    return min(cost1, cost2);
}

int main() {
    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    printf("%d\n", low_cost(x, y, n));
    return 0;
}