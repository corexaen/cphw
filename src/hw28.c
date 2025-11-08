#include <stdio.h>
#include <stdlib.h>
typedef struct _Point {
    int x;
    int y;
} Point;
int move_xy(Point* now, Point d, int** arr) {
    now->x += d.x;
    now->y += d.y;
    return arr[now->y][now->x];
}
int line_sum(Point start, Point direction, int length, int** arr) {
    int sum = arr[start.y][start.x];
    Point now = start;
    for(int i = 0; i < length - 1; i++) {
        sum *= 10;
        sum += move_xy(&now, direction, arr);
    }
    return sum;
}
Point find_near_max_direction(Point now, Point directions[], int dir_count, int** arr) {
    int max = -1;
    Point result = {0, 0};
    for(int i = 0; i < dir_count; i++) {
        Point near = { now.x + directions[i].x, now.y + directions[i].y };
        if(arr[near.y][near.x] > max) {
            max = arr[near.y][near.x];
            result = directions[i];
        }
    }
    return result;
}
int get_max_move(int** arr, int n) {
    int max = -1, result = -1;
    for(int y = n; y < n * 2; y++) {
        for(int x = n; x < n * 2; x++) {
            if(arr[y][x] > max) {
                max = arr[y][x];
            }
        }
    }
    Point direction[] = { {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1} };
    for(int y = n; y < n * 2; y++) {
        for(int x = n; x < n * 2; x++) {
            if(arr[y][x] == max) {
                Point now = { x, y };
                Point dir = find_near_max_direction(now, direction, 5, arr);
                int sum = line_sum(now, dir, n, arr);
                if(sum > result) {
                    result = sum;
                }
            }
        }
    }
    return result;
}
int main() {
    int n;
    scanf("%d ", &n);
    int** arr = (int**)malloc(n * 3 * sizeof(int*));
    for(int i = 0; i < n * 3; i++) {
        arr[i] = (int*)malloc(n * 3 * sizeof(int));
    }
    for(int y = 0 ;y<n;y++) {
        for(int x=0;x<n;x++) {
            int val;
            char c;
            scanf(" %c", &c);
            val = c - '0';
            for(int dy=0;dy<3;dy++) {
                for(int dx=0;dx<3;dx++) {
                    arr[dy * n + y][dx * n + x] = val;
                }
            }
        }
    }
    int result = get_max_move(arr, n);
    printf("%d\n", result);
    for(int i = 0; i < n * 3; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}