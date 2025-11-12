#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    bool A[2000] = {false,};
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        A[x - 1] = true;
    }
    for(int i = 0; i < 2000; i++) {
        if(!A[i]) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}