#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int count_good_integers(int* weights, int n, int w) {
    int count = 0;
    bool* good_integer = (bool*)malloc(w * sizeof(bool));
    memset(good_integer, false, w * sizeof(bool));
    for(int i = 0; i < n; i++) {
        if(weights[i] <= w) {
            good_integer[weights[i]] = true;
        }
        for(int j = i + 1; j < n; j++) {
            if(weights[i] + weights[j] <= w) {
                good_integer[weights[i] + weights[j]] = true;
            }
            for(int k = j + 1; k < n; k++) {
                if(weights[i] + weights[j] + weights[k] <= w) {
                    good_integer[weights[i] + weights[j] + weights[k]] = true;
                }
            }
        }
    }
    for(int i = 0; i < w; i++) {
        if(good_integer[i]) {
            count++;
        }
    }
    free(good_integer);
    return count;
}

int main() {
    int n, w;
    scanf("%d %d", &n, &w);
    int* weights = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    int result = count_good_integers(weights, n, w);
    printf("%d\n", result);
    free(weights);
    return 0;
}