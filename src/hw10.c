#include <stdio.h>
typedef struct __Time {
    int hour;
    int minute;
} Time;
Time add_time(const Time t1, const Time t2) {
    Time result;
    result.hour = (t1.hour + t2.hour + (t1.minute + t2.minute) / 60) % 24;  // 24시간 형식, 분이 60분 넘으면 시간에 그만큼 추가
    result.minute = (t1.minute + t2.minute) % 60;                           // 분은 60분 형식
    return result;
}
int main() {
    Time t1 = {21, 0}, t2 = {0, 0};
    scanf("%d", &t2.minute);

    Time t3 = add_time(t1, t2);
    printf("%02d:%02d\n", t3.hour, t3.minute);
    return 0;
}