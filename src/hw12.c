#include <stdio.h>
#include <stdlib.h>
void generate_triangle(int n, int* tri) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                tri[i * n + j] = 1; // 가장자리 값은 1
            } else {
                tri[i * n + j] = tri[(i - 1) * n + (j - 1)] + tri[(i - 1) * n + j]; // 위의 두 값의 합
            }
        }
    }
}
void print_triangle(int n, int* tri) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", tri[i * n + j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int* tri = (int*)malloc(n * n * sizeof(int));
    memset(tri, 0, n * n * sizeof(int));
    generate_triangle(n, tri);
    print_triangle(n, tri);
    free(tri);
    return 0;
}