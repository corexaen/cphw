#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int move_all_products(int* boxes, int w) {
    int thrown = 0;
    for(int i = 3; i >= 0; i--) {
        if(boxes[i]) {
            if(i + w <= 3) {
                boxes[i + w] += boxes[i];
                boxes[i] = 0;
            } else {
                thrown += 1;
                boxes[i] = 0;
            }
        }
    }
    return thrown;
}
int main() {
    int n;
    scanf("%d", &n);
    int* boxes = (int*)malloc(4 * sizeof(int));
    int result = 0;
    memset(boxes, 0, 4 * sizeof(int));
    for(int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        boxes[0] = 1;
        result += move_all_products(boxes, w);
    }
    printf("%d\n", result);
    free(boxes);
    return 0;
}