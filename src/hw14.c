#include <stdio.h>

int getWorld(int state) {
    return ((state >> 3) & 0b111) + 1;
}
int getStage(int state) {
    return (state & 0b111) + 1;
}
int getState(int world, int stage) {
    return ((world - 1) << 3) | (stage - 1);
}

int main() {
    int w,s;
    scanf("%d-%d", &w, &s);
    int state = getState(w, s);
    state++;
    printf("%d-%d\n", getWorld(state), getStage(state));
    return 0;
}