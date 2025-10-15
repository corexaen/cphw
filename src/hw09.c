#include <stdio.h>
int get_height(int N, int M, int X, int T, int D) {
    return M < X ? T - (X - M) * D : T;             // 성장이 멈춘 후라면 높이 변화 없음, 아니면 감소
}
int main(void) {
    int N, T, D, X, M;
    scanf("%d %d %d %d %d", &N, &M, &X, &T, &D);

    printf("%d\n", get_height(N, M, X, T, D));
    return 0;
}