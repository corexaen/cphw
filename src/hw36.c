#include <stdio.h>

int main() {
    int n;
    scanf("%d ", &n);
    int x = 0,y = 0, d = 0;
    for(int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        if(c == 'S') {
            switch (d) {
                case 0: x++; break;
                case 1: y--; break;
                case 2: x--; break;
                case 3: y++; break;
            }
        }
        if(c == 'R') {
            d = (d + 1) % 4;
        }
    }
    printf("(%d, %d)\n", x, y);
    return 0;
}