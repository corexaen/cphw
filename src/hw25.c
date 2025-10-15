#include <stdio.h>
int find_trash(char* a, char* b) {
    /*
    sick = 0
    fine = 1
    0 1 = 2
    1 1 = 4
    1 0 = 3
    0 0 = 1
    */
    return (int)(((!(*a - 'f')) << 1) | (!(*b - 'f'))) + 1;
}
int main() {
    char s1[5], s2[5];
    scanf("%s %s", s1,s2);
    printf("%d\n", find_trash(s1,s2));
}