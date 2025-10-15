#include <stdio.h>
int get_height(int N, int M, int X, int T, int D) {
    return M < X ? T - (X - M) * D : T;
}
int main(void) {
    int N, T, D, X, M;
    scanf("%d %d %d %d %d", &N, &M, &X, &T, &D);

    printf("%d\n", get_height(N, M, X, T, D));
    return 0;
}