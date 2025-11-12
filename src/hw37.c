#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(n * sizeof(int));
    int count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", B + i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                if(A[i] == B[j]) {
                    count1++;
                }
            }
            else {
                if(A[i] == B[j]) {
                    count2++;
                }
            }
        }
    }
    printf("%d\n%d\n", count1, count2);
    free(A);
    free(B);
    return 0;
}