#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move_beads(int* beads, int n, int l) {
    if(beads[l] == n) {
        return;
    }
    if(beads[l + 1] != beads[l] + 1) {
        beads[l]++;
    }
}

int main() {
    int n,k,q;
    scanf("%d %d %d", &n, &k, &q);
    int *beads = (int*)malloc(k * sizeof(int));
    for(int i = 0; i < k; i++) {
        scanf("%d", beads + i);
    }
    for(int i = 0; i < q; i++) {
        int l;
        scanf("%d", &l);
        move_beads(beads, n, l - 1);
    }
    for(int i = 0; i < k; i++) {
        printf("%d ", beads[i]);
    }
    printf("\n");
    free(beads);
    return 0;
}