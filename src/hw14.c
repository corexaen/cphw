#include <stdio.h>

int getWorld(int state) {
    return ((state >> 3) & 0b111) + 1;          // 상위 3비트를 오른쪽으로 3비트 이동 후 하위 3비트만 추출
}
int getStage(int state) {
    return (state & 0b111) + 1;                 // 하위 3비트만 추출
}
int getState(int world, int stage) {
    return ((world - 1) << 3) | (stage - 1);    // 1-8을 0-7로 바꾼 후 3비트씩 나눠 하나의 변수로 저장
}

int main() {
    int w,s;
    scanf("%d-%d", &w, &s);
    int state = getState(w, s);                 // 8월드 8스테이지까지만 있기에 3비트씩 나눠 하나의 변수로 저장
    state++;
    printf("%d-%d\n", getWorld(state), getStage(state));
    return 0;
}