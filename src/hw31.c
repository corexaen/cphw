#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, k, max = 0;
    scanf("%d %d", &n, &k);
    int* tast = (int*)malloc(n * sizeof(int));
    bool* want = (bool*)malloc(n * sizeof(bool));
    for(int i = 0; i < n; i++) {
        scanf("%d", tast + i);
        want[i] = 1;
        if(tast[i] > max) {
            max = tast[i];
        }
    }
    for(int i = 0; i < k; i++) {
        int n = 0;
        scanf("%d", &n);
        want[n - 1] = 0;
    }
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(!want[i] && tast[i] == max) {
            printf("YES\n");
            found = true;
            break;
        }
    }
    if(!found) {
        printf("NO\n");
    }
    free(tast);
    free(want);
    return 0;
}